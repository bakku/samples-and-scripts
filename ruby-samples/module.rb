module OwnMath
	def addNumbers(num1, num2)
		num1 + num2
	end
	public:addNumbers
end

include OwnMath

puts addNumbers(1, 2)
