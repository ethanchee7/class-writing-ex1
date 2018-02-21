//  Created by Ethan Chee on 1/23/18.
//  I, Ethan Chee, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//  I did not copy code from anyone, student or otherwise.
//
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#ifndef VectorString_hpp
#define VectorString_hpp

#include <memory>
#include <stdio.h>
#include <string>

namespace pic10b
{
    
    /**
     * This class mimics the std::vector class
     */
    class VectorString
    {
    public:
        /**
         * Default constructor, sets size to 0, cap to 1, pointer to string array initialized with cap.
         */
        VectorString();
        
        /**
         * Constructor taking in one argument, sets size to input argument, cap to double size, pointer to string array initialized with cap.
         */
        VectorString(size_t size);
        
        /**
         * Constructs VectorString object with a given size and string, sz is set to input variable size, and cap is double size. Px is a pointer to a string array initialized with cap.
         */
        VectorString(size_t size, const std::string& s);
        
        /**
         * Constructs identical VectorString object when given another VectorString object by reference.
         */
        VectorString (const VectorString& v);
        
        /**
         * Takes data from an r-value reference and assigns it to a newly constructed VectorString object.
         */
        VectorString (VectorString&&);
        
        /**
         * Returns the size of a VectorString object.
         * @return Value of the size member variable
         */
        size_t size() const;
        
        /**
         * Returns the capacity of a VectorString object.
         * @return Value of the capacity member variable
         */
        size_t capacity() const;
        
        /**
         * Adds a string s to the end of the array of strings that px points to.
         * @param s The string that we want to push back onto our string array
         */
        void push_back(const std::string& s);
        
        /**
         * Remove the last entry on our array of strings in our VectorString object.
         */
        void pop_back();
        
        /**
         * Delete an entry at a given index argument in our array of strings.
         * @param index The location in our array that we want to delete from
         */
        void deleteAt(size_t index);
        
        /**
         * Add an entry at a given index argument in our array of strings.
         * @param index The location in our array that we want to insert at
         * @param s The string we want to insert into our array
         */
        void insertAt(size_t index, const std::string& s);
        
        /**
         * Return the string at a given index of our array
         * @param index The location in our array that we want to insert at
         * @return The string that lies in the index location of our array
         */
        std::string& at(size_t index);
        
        
    private:
        
        //Member variable representing the size of our array
        size_t sz;
        //Member varaible representing the capacity of our array
        size_t cap;
        //Unique pointer pointing at an array of strings
        std::unique_ptr<std::string[]> px;
        
    };

}

#endif /* VectorString_hpp */

