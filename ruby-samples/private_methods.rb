class Maths
	def times_two(a)
		puts "#{a} * 2 = #{engine(a)}"
	end
	
	def engine(b)
		b + b
	end
	private.engine(4) # comment this line so you can use engine like shown below
end

Maths.new.times_two(4)
# does not work: Maths.new.engine(4)
