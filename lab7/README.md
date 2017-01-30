#Lab 7 Hash

You will be comparing three different open addressing schemes.

Q1. Complete the following functions in hash.cpp:
```c++
void Hash::qinsert(int k) {
// Insert k in the hash table.
// Use open addressing with quadratic probing and hash(k) = k % m.
void Hash::linsert(int k) {
// Insert k in the hash table.
// Use open addressing with linear probing and hash(k) = k % m.
void Hash::dinsert(int k) {
// Insert k in the hash table.
// Use open addressing with double hashing. Use the existing hash function
// and also implement a second hash function.
```
You must complete these functions so that they call tallyProbes on every successful insertion, with the number of probes required for that insertion. Note that
```sh
./hash q 900000 1000000
```
will insert 900,000 random keys into a hash table of size 1,000,000 using quadratic probing, while
```sh
./hash d 8000 10000
```
will insert 8,000 random keys into a hash table of size 10,000. Replacing the d with an l will insert keys using linear probing.

To print out hash table after insertion, using the -v flag
```sh
./hash -v q 900000 1000000
```

Q2. Run a few experiments to see how the average number of probes per insertion differs when using the different methods and different load factors.

You should think of this as a regular scientific experiemnt that generates data.

You need to run enough experiements to justify your conclusions, and you need to use a table large enough.

Try to make the table as large as possible such that you don’t have to wait and unreasonable amount of time for the results.

Answer the following questions:

(i) Under what load factors is linear probing just as good as quadratic probing? When does quadratic begin to win out?

(ii) How does the choice of hash function affect double hashing? Can you devise a hash function that makes double hashing just as good as quadratic probing? Can you make it even better? Make sure you try a few to be able to justify your answer.

(iii) When does double hashing begin to win against both of the other schemes? (i.e. at what capacities and load factors do you see a significant gain over the other methods?)

(iv) Finally, which open addressing scheme would you choose and why? Would you always choose this scheme?

Q3. Modify the main method in driver.cc to automate some of your experiments from question 2. You can run your added experiment code using:
```sh
./hash
```
For example, you could add something like this:
```c++
Hashtable H(10000);
for (int i = 0; i < 7500; i++) {
linsert(rand() + 1);
}
cout << "Linear with 7500 keys and size 10000: ";
H.printStats();
```
to automatically see how insert with linear probing performs when inserting 7,500 keys into a hash table of size 10,000.

What other experiments might you automate to help you answer the questions from 2?
