# ONLINE MOVIE TICKETING_ENGG 1340 Project

## u3035603930 Lee Yoon Jeong,      u3035557363 Jaemin Kim

### An online movie ticketing system allowing users to buy, refund or edit their online booked movie tickets written in C++11


## Problem Statement

  Movie Industry have been loved by many people. These people will normally purchase their movie tickets in the cinema counter (offline) and directly head into watch movie. However, in many walk-in cases, there are high chance of customers missing their movie tickets on desired time due to sold out or even because they arrived late (with unexpected reasons)
  
  For many people, it would be really convenient if they can buy or refund movie tickets through online. This system will provide an easy pathway of buying movie tickets for the customers. As well as adding/deleting/editing the records

The purpose of this project is to:

	1. Provide convenient platform for the users
	2. Allows the user to search/select movie
	3. Store user information (Creating an output file for individual users who bought ticket)
	4. Display user information
	5. Allow user to delete the booking
	6. Users can add comment on Movie

## Function

### AddRecord():

  exit (if there is no Record file)
  
  Receiving inputs:
  
    1)Booking number
    2)Customer name
    3)Movie name
    4)Movie Schedule (date)
    5)Time(24hr)
    6)Ticket type
    7)Total fee
    
  Ask if the user wants to add on to the Recoed
  
    if Yes:
      return back to repeat the receiving input step
    if No:
      return back to main page
    ** "Customer.txt" sample file created already. It will be used to check if the codes run successfully
  
### DisplayAll():
  
    open file "Movie.txt"
    if unable to open the file -> error message
    if record number>= 5, show message "You sure you want to display these many records?"
 
### ModifyRecords():
 
  Display all current record <= call DisplayAll() function
  Search records by Booking number
    - receives information individually (seperately)
    - Add on the individually received information to each file
  Ask message "Modify more?"
    "Yes" -> go back and repeat
    "No" -> exit to main
 
### SearchRecord():

  Search by Booking number
  Display the corresponding information
  Ask message "Do you want to search more?"
  
### MovieInfo():

  Movie name listed 1), 2), 3)... calling detailed information of each     movie by users choosing the number
  ** "Movie.txt" file already created by us -> sample use to test if t    he code runs successfully
  
  
  

