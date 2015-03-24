# Implementation of an easy Stack as a class

class Stack
	def initialize()
		@stack = [];
	end
	
	def is_empty()
		return @stack.empty?
	end
	
	def pop()
		if (is_empty)
			return nil
		else
			return @stack.pop
		end
	end
	
	def push(x)
		@stack.push(x)
	end
	
	def top()
		if (is_empty)
			return nil
		else
			return @stack[@stack.length-1]
		end
	end
end
