msg1 = proc {
	puts "everything is great!!"
}

err = proc {
	puts "oh no! an error occured!!"
}

def run(p)
	puts "the program wants to print a message!!"
	p.call
end

run(msg1)
run(proc { puts "still everything great !" })
run(err)
