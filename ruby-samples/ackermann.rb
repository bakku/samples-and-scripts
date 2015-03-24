# the ackermann function

def ackermann(x, y)
	if x == 0
		print "#{y}+1\n"
		return y + 1
	elsif y == 0
		print "ackermann(#{x}-1, 1)\n"
		return ackermann(x-1, 1)
	end
	
	print "ackermann(#{x}-1, ackermann(#{x}, #{y}-1))\n"
	return ackermann(x-1, ackermann(x, y-1))
end

puts ackermann(ARGV[0].to_i, ARGV[1].to_i)
