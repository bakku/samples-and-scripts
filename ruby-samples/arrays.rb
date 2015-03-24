# different datatypes in one array

array = [1, 2, "3", 4.0, 5]
print array
puts


# concatenation of arrays

print array + [6, 7]
puts


# index numbers of arrays

print array[0, 2] # beginning from element 0 --> two elements
puts
print array[0..2] # from element 0 to element 2 --> 3 elements
puts
print array[-3, 2] # from the third last element --> two elements
puts
print array[-5..-3] # from the fith last element to the third last element --> 3 elements
puts


# arrays to strings and strings to arrays

print array.join(":") + "\n" # from array to string --> ":" between elements
str = "h:a:l:l:o"
print str.split(":") # from string to array --> uses ":" as split-character
puts


# hashes use keys as indexes
# keys can be various datatypes

hash = { "key1" => 1, 3.0  => 5 } # creates hash table
puts hash # prints full hash table
puts hash["key1"] # prints one hash value

hash[7] = 2 # inserts new value with 7 as key
puts hash[7] 

hash.delete "key1" # deletes value with key = "key1"
puts hash

