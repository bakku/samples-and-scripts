# iterators for strings

"abc".each_byte { |c| printf "%c", c }
print "\n"

"a\nb\nc\n".each_line { |l| print l.chomp } # prints each line without newline
print "\n"


