# ONLINE MOVIE TICKETING_ENGG 1340 Project

## u3035603930 Lee Yoon Jeong,      u3035557363 Jaemin Kim

### An online movie ticketing system allowing users to buy, refund or edit their online booked movie tickets written in C++11


### Problem Statement





### Function

AddRecord():

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
  
  DisplayAll():
  
    open file "Movie.txt"
    if unable to open the file -> error message
    if record number>= 5, show message "You sure you want to display these many records?"
 
 ModifyRecords():
 
  Display all current record <= call DisplayAll() function
  Search records by Booking number
    - receives information individually (seperately)
    - Add on the individually received information to each file
  Ask message "Modify more?"
    "Yes" -> go back and repeat
    "No" -> exit to main
 
SearchRecord():

  Search by Booking number
  Display the corresponding information
  Ask message "Do you want to search more?"
  
MovieInfo():

  Movie name listed 1), 2), 3)... calling detailed information of each     movie by users choosing the number
  ** "Movie.txt" file already created by us -> sample use to test if t    he code runs successfully
  
  
  

