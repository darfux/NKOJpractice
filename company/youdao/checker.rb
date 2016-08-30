require '../../checker_base'

def generator
	size = rand(1000)
	(0...size).map { (97 + rand(26)).chr }.join
end

def algorithm(input)
	hash = {}
	str = input
	for i in 0...str.length
		for j in (i+1)...str.length
			tmp = str.dup
			tmp.slice!(i)
			tmp.slice!(j-1)
			hash[tmp] = true
		end
	end
	hash.size
end



do_check



