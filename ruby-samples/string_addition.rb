# useful additions to the String class in ruby
# require this File and you can just use these methods with your Strings

class String

	# numeric? - checks whether String is numeric or not
	# for further information see: http://mentalized.net/journal/2011/04/14/ruby-how-to-check-if-a-string-is-numeric/
	def numeric?
		begin
			return Float(self) != nil
		rescue
			return false
		end
	end
end
			
