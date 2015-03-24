# case (like switch)

i = 8

case i
	when 1, 2..5
		puts "1-5"
	when 6..10
		puts "6-10"
end

str = "abcdef"

case str
	when "ab"
		puts "ab"
	when /def/ # reg expression
		puts "contains def"
end


# while

i = 0

while true
	i = i + 1
	
	next unless i == 9 # if i != 9 it "continues"
	
	break if i > 8 # is only called when i == 9
end

puts i


# for

for num in (5..10)
	print num.to_s + " "
end
print "\n"


for element in ["i am", 8, "years old"]
	print element.to_s + " "
end
print "\n"
