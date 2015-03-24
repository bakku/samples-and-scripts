# global vars:

def printvar
	puts "#{$globalvar}"
end

$globalvar = "hello"
printvar

trace_var :$globalvar, proc {print "$globalvar is now ";printvar}
$globalvar = "bye"
printvar

# there are system global vars. example:

puts "name of the ruby script file: #{$0}"


# instance vars:

class InstVar
	def set_var1(n)
		@var1 = n
	end
	
	def set_var2(n)
		@var2 = n
	end
	
	def get_vars
		puts "var1: #{@var1}, var2: #{@var2}"
	end
end

obj = InstVar.new
obj.set_var1(1)
obj.get_vars # before set_var2 has not been called, @var2 is not a part of the object "obj" yet
obj.set_var2(3)
obj.get_vars


# local vars:

locvar = 14
puts defined?(locvar)

def bla
	str = "hello"
	puts defined?(str)
end

bla
puts defined?(str)


# constants (start with an uppercase letter)

Hello = "hello"
puts Hello
Hello = "bye" # is possible but a warning will be printed out
puts Hello

class Vars
	Var1 = 1
	Var2 = 2
	Var3 = 3
end

puts Vars::Var1

module VarModule
	Greeting = "Hello"
	Farewell = "Bye"
end

include VarModule

puts Greeting



