# difference between '' and ""
# '' does not allow e.g. \n , #{ ... } , ...

puts "hello\nworld"
puts 'hello\nworld'


# string concatenation (a bit like java)

puts "hello" + " world"
puts "hello world" * 2


# extracting characters

word = "helloworld"

puts word[0] # positive (and 0) means from the beginning
puts word[-1] # negative means beginning from the end


# extracting substrings

puts word[0, 4] # beginning from 0: 4 letters
puts word[-3, 2] # begging from the last 3 letters: 2 letters

puts word[0..3] # from letter 0 to letter 3
puts word[-7..-4] # from the seventh last letter the fourth last letter


# testing strings

puts "hello" == "hello"
puts "hello" == "bye"


