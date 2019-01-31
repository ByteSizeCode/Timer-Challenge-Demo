//
//  main.cpp
//  Timer Challenge Demo
//
//  Created by Isaac Raval on 4/26/18.
//  Copyright © 2018 Isaac Raval. All rights reserved.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>
#include <stdio.h>

using namespace std;

time_t NumOfSecondsToday() {
    time_t t1, t2;
    struct tm tms;
    time(&t1);
    localtime_r(&t1, &tms);
    tms.tm_hour = 0;
    tms.tm_min = 0;
    tms.tm_sec = 0;
    t2 = mktime(&tms);
    return (t1-t2);
}

string GenerateRandomString() {
    const int SIZE_OF_STRING_TO_GENERATE = 4;
    int randNum = 0;
    string stringToReturn = "";
    
    vector<char> CharArray {'0','1','2','3','4', '5','6','7','8','9','a','b','c','d','e','f', 'g','h','i','j','k', 'l','m','n','o','p', 'q','r','s','t','u', 'v','w','x','y','z'
    };
    
    //Loop SIZE_OF_STRING_TO_GENERATE times
    for(int i = 0; i < SIZE_OF_STRING_TO_GENERATE; i++) {
        //Generate random number
        randNum = rand() % CharArray.size();
        
        //Add to string to return
        stringToReturn += CharArray.at(randNum);
    }
    
    //Return random string
    return stringToReturn;
};

int main() {
    srand(time(0));
    
    int startTime = 0;
    int endTime = 0;
    int timeTaken = 0;
    string correctString = "";
    string userAnswer = "";
    int points = 0;
    char difficulty = '.';
    int numSecondsAllowedToAnswer = 0;
    const int NUM_QUESTIONS_TO_ASK = 5;
    
    //Input difficulty level
    while (difficulty != 'e' && difficulty !=  'm' && difficulty != 'h') {
        cout << "Please Select " << endl
             << "Easy, Medium, or Hard (e, m, h):"
             << endl;
        
        cin >> difficulty;
        
        //Flush Buffer
        cin.clear();
        cin.ignore(1000, '\n');
    }
    
    if (difficulty == 'e') {
        numSecondsAllowedToAnswer = 4;
        cout << "Easy Mode Selected" << endl;
    }
    else if (difficulty == 'm') {
        numSecondsAllowedToAnswer = 3;
        cout << "Medium Mode Selected" << endl;
    }
    else if (difficulty == 'h') {
        numSecondsAllowedToAnswer = 2;
        cout << "Hard Mode Selected" << endl;
    }
    
    cout << "Enter the text you see within "
         << numSecondsAllowedToAnswer
         << " seconds to get a point"
         << endl
         << "There will be " << NUM_QUESTIONS_TO_ASK << " rounds"
         << endl;
    
    this_thread::sleep_for (chrono::seconds(2));
    
    cout << "Ready" << endl;
    
    this_thread::sleep_for (chrono::seconds(1));
    
    cout << "Get Set" << endl;
    
    this_thread::sleep_for (chrono::seconds(1));
    
    cout << "Go!" << endl;
    
    this_thread::sleep_for (chrono::seconds(1));
    
    //Code for rounds
    for(int numProblemsGiven = 0; numProblemsGiven < NUM_QUESTIONS_TO_ASK; numProblemsGiven++) {
        
        correctString = GenerateRandomString();
        
        cout << correctString << endl;
        
        startTime = NumOfSecondsToday();
        
        getline(cin, userAnswer);
        
        endTime = NumOfSecondsToday();
        
        timeTaken = endTime - startTime;
        
        if (timeTaken > numSecondsAllowedToAnswer) {
            cout << endl << "Too late! -2 points" << endl;
            
            points -= 2;
        }
        
        else if (userAnswer == correctString) {
            
            cout << endl << "VALID! 1 point" << endl;
            
            points += 1;
            
        } else {
            cout << endl << "Invalid -2 points" << endl;
            
            points -= 2;
        }
        
        this_thread::sleep_for (chrono::seconds(1));
    }
    
    cout << endl << "Finished! Points: " << points << endl
         << endl;
    
    return 0;
}
