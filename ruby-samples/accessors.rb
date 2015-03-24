class Fruit
	attr_accessor :type, :condition # automatically creates getter and setter
	
	def print
		puts "this #{@type} is #{@condition}"
	end
end

f1 = Fruit.new
f1.type = "apple" # setter
f1.condition = "ripe" # setter
f1.print
puts "this #{f1.type} is #{f1.condition}" # calls getter

f2 = Fruit.new
f2.print # does not work yet
puts f2.type # does not work yet


# initialization

class Animal
	def initialize(n, a, t = "animal") # can be given default values
		@name = n
		@age = a
		@type = t
	end
	
	def print
		puts "my name is #{@name}, i am #{@age} old and i am a(n) #{@type}"
	end
end

a1 = Animal.new("kitty", 5, "cat")
a1.print

a2 = Animal.new("steven", 7)
a2.print


	
	

