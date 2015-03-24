# a singleton method is a method of an instance which has a different functionality than the other instances of the same class

class SingletonMethod
	def age?
		18
	end
end

age18 = SingletonMethod.new
puts age18.age?

age14 = SingletonMethod.new
def age14.age?
	14
end
puts age14.age?
