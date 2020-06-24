
# String

To use string first of all you have to include ` <string> `

## Declaring and Initializing a String 
It is very easy to declare a string. You can create a string variable nammed as MyString by typing **` string MyString ; `**

You can declare several string togather in a line. You can also _**initialize**_ a string using **` string MyString = "Hello World!" `**. 
You can also do that later in your code.

You can take a string from the user using **` cin >> MySting ; `** which only takes the sting _**up to a space**_

If you want to get _**a full line including spaces**_ use this instead  **` getline( cin , MyString ) ; `**

## Basic Sting Operations

Lets say you have two strings **` string a = "Hello " , b = "World" ; `** You can add string **b** after string **a** using **` a = a + b `**
after this opatertion the value of a will be **"Hello World"**. 
That is how you can **concatenate** two strings.
