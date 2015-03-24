# how to try and catch with exceptions

def first_line
	begin
		print "input file name: "
		STDOUT.flush
		filename = gets.chomp
		file = open(filename)
		line = file.gets
		file.close
		puts line
	rescue
		puts "could not open file."
		retry
	end
end

first_line


# how to raise exceptions

def two_lines
	begin
		print "input file name: "
		STDOUT.flush
		filename = gets.chomp
		file = open(filename)
		line = file.gets
		puts line
		line = file.gets
		puts line
		file.close
	rescue
		raise "could not open file" # with raise one can raise exceptions
	end
end

two_lines


# keyword ensure

def three_lines
	print "input file name: "
	STDOUT.flush
	filename = gets.chomp
	file = open(filename)
	begin
		for i in 0..2
			line = file.gets
			puts line
		end
	rescue
		puts "could not open file."
	ensure # ensure will ensure that the file will be closed. after begin and/or after rescue
		file.close
	end
end

three_lines
