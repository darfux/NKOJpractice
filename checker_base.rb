require 'benchmark'
require 'etc'

@exit_flag = false
def do_check
	children = []
	ncpu = Etc.nprocessors
	puts "Detected CPU number: #{ncpu}"
	for i in 0...ncpu
		p = fork do
			loop do
				res = Benchmark.measure do
					for i in 0...10
						exit if @exit_flag
						input = generator

						to_check =  `bash -c "printf '#{input}' | ./main.out"`
						truth = algorithm(input)

						if to_check.to_i != truth
							puts "Catched unmatched result!"
							puts " [input] #{input}\n [to_check] #{to_check}\n [truth]#{truth}"
							@exit_flag = true
							exit
						end
					end
				end
				puts Process.pid, res
			end
		end
		children << p
	end

	children.each { |p| Process.waitpid(p) }
end
