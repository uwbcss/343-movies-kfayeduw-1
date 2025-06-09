# Self-Evaluation

## Name(s): 

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0 (Yes)

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: Full
History: Full
Borrow: Full
Return: Full


Q: -1 for each compilation warning, min -3: 0 (No warnings)

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0 (No warnings)

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0 (No warnings)

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0 (No memory leaks)

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0 (Sufficiently tested)

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0 (Yes)

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

invalid command code: command.cpp --> create()

invalid movie type: movie.cpp --> create()

invalid customer ID: borrowcommand.cpp --> execute() AND returncommand.cpp --> execute()
 
invalid movie: borrowcommand.cpp --> execute() AND returncommand.cpp --> execute()

factory classes: movie.h/cpp AND command.h/cpp

hashtable: I created a simple map class called CustomerMap (customermap.h/cpp) which holds all customer information. It uses customer IDs as keys and Customer* objects as values. It is used in the Store singleton class (store.h/cpp) as an object called "customerMap". (explain what the hashtable is used for)

container used for comedy movies: unordered_map (found in store.h --> inventory)

function for sorting comedy movies: store.cpp --> addMovieToInventory()

function where comedy movies are sorted: store.cpp --> addMovieToInventory()

functions called when retrieving a comedy movie based on title and year: comedy.cpp --> fromBRString()

functions called for retrieving and printing customer history: TODO(student) historycommand.cpp --> init(), THEN execute()

container used for customer history: vector<struct> (found in customer.h --> history)

functions called when borrowing a movie: TODO(student) borrowcommand.cpp --> init(), THEN execute()

explain borrowing a movie that does not exist: In borrowcommand.cpp --> execute(): The function fromBRString() is used to search for a Movie* object based on the input string from the command. Each subclass of Movie has its own implementation of this function, since each type of movie will be formatted and ordered differently. This function will return nullptr if the movie is not found. So, if nullptr is returned, an error message will be printed and the command will stop executing.

explain borrowing a movie that has 0 stock: In borrowcommand.cpp --> execute(): The last line of code calls customer.cpp --> borrowItem(). This function takes a Movie* object (m) as one of its parameters. It will check if m->stock < 1. If stock is less than 1, it will print an error message and stop executing.

explain returning a movie that customer has not checked out: In returncommand.cpp --> execute(): The last line of code calls customer.cpp --> returnItem(). This function takes a Movie* object (m) as one of its parameters. It creates a boolean called "borrowed", initialized to false. Then, it iterates through the customer's history looking for transactions with the same movie. If the most recent transaction was a borrow, then the "borrowed" boolean is set to true. Otherwise it is set to false. Of course if there are no past transactions with this movie, "borrowed" will stay false. If "borrowed" is false after this iteration, an error message is printed and execution stops. The attempted return is not logged in the user's history.

any static_cast or dynamic_cast used: In comedy.cpp, drama.cpp, and classic.cpp. static_cast is used in each of their compare functions (compareComedy(), compareDrama(), and compareClassic()), and in each of their fromBRString() functions.

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? Yes




Q: Total points: 30