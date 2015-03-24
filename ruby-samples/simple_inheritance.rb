class Mammel
	def breathe
		puts "inhale and exhale"
	end
	
	def walk
		puts "walk on two legs"
	end
	
	def identify
		puts "i'm a mammel"
	end
	
	def eat(age)
		if age > 8
			puts "a lot to eat"
		else
			puts "less to eat"
		end
	end
end

class Cat < Mammel
	def speak
		puts "Meow"
	end
	
	def walk
		puts "i'd rather walk on four legs"
	end
	
	# super calls identify of mammel first
	def identify
		super 
		puts "i'm a cat too"
	end
	
	def eat(age)
		super(age)
	end
end

class DishonestCat < Mammel
	def eat(age)
		super(10)
	end
end

tama = Cat.new
tama.breathe
tama.speak
tama.walk
tama.identify
tama.eat(6)
DishonestCat.new.eat(10)
