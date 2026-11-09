Analyze the results:

when i implemented the linked list i opted for a single linked list with a tail. Simply because of the simple implementation. And not have to manage two pointers.

-how the number of comparisons for find() demonstrate o(n) complexity

the find comparison as tested in find for account id shows that number of comparisons are the exact number of the account id. so when we test for n account number we get n number of accounts compared. Same with out of range, then we se it stops at the end of the list.


-what is the key difference in flexibility between using the generic every() method with a callback versus a spesific PrintEveryAccountInDateRange() function

Every with callback gives a reusable code that can easily be changed to fit the search criteria, without changing the class. For a system that changes search criterias often the more generell solution is the best. I did also see that timespent was significaly bigger in the standalone function, but i think it is because of print it did the print work ass wel, but the generic function returned a list and was printed after.

why i chooce single linked list (with tail)
-simple