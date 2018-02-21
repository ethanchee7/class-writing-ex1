//
//  VectorString.cpp
//  hw3
//  Created by Ethan Chee on 1/23/18.
//  I, Ethan Chee, declare that this work is my own. I did this work honestly and can fully stand behind everything that I have written.
//  I did not copy code from anyone, student or otherwise.
//
//  Copyright © 2018 Ethan Chee. All rights reserved.
//

#include "VectorString.h"

/**
 * Implementation of member functions in our VectorString class
 */

namespace pic10b // Open up our namespace
{
    /**
     * Default constructor, sets size to 0, cap to 1, pointer to string array initialized with cap.
     */
    VectorString::VectorString() : sz(0), cap(1), px(new std::string[cap]){}
    
    /**
     * Constructor taking in one argument, sets size to input argument, cap to double size, pointer to string array initialized with cap.
     */
    VectorString::VectorString(size_t size): sz(size), cap(2.0*size), px(new std::string[cap]) {}
    
    /**
     * Constructs VectorString object with a given size and string, sz is set to input variable size, and cap is double size. Px is a pointer to a string array initialized with cap.
     */
    VectorString::VectorString(size_t size, const std::string& s): sz(size), cap(2.0*size), px(new std::string[cap])
    {
        // Run for loop until we've gone through the entire size of our string array
        for (size_t i = 0; i < sz; ++i)
        {
            //Make each index in the array equal to the string variable
            px[i] = s;
        }
    }
    
    /**
     * Constructs identical VectorString object when given another VectorString object by reference.
     */
    VectorString::VectorString (const VectorString& v): sz(v.sz), cap(v.cap), px(new std::string[cap])
    {
        // Run for loop until we've gone through the entire size of our string array
        for (size_t i = 0; i < sz; ++i)
        {
            //Set value of new object's pointer equal to the copied objects pointer at each index
            px[i] = v.px[i];
        }
    }
    
    /**
     * Takes data from an r-value reference and assigns it to a newly constructed VectorString object.
     */
    VectorString::VectorString(VectorString&& v): sz(v.sz), cap(v.cap), px(new std::string[cap])
    {
        //Swap the pointer addresses between pointer px and r-value object's px
        std::swap(px,v.px);
    }
    
    /**
     * Returns the size of a VectorString object.
     * @return Value of the size member variable
     */
    size_t VectorString::size() const
    {
        return sz;
    }
    
    /**
     * Returns the capacity of a VectorString object.
     * @return Value of the capacity member variable
     */
    size_t VectorString::capacity() const
    {
        return cap;
    }
    
    /**
     * Adds a string s to the end of the array of strings that px points to.
     * @param s The string that we want to push back onto our string array
     */
    void VectorString::push_back(const std::string& s)
    {
        //If adding one to the causes us to go over the capacity variable
        if (sz + 1 > cap)
        {
            //Double the capacity of our current VectorString object
            cap = 2 * cap;
            //Create a new unique pointer that points to an array of strings with new cap size
            std::unique_ptr<std::string[]> newPoint(new std::string[cap]);
            // Run for loop until we've gone through the entire size of our string array
            for (size_t i = 0; i < sz; ++i)
            {
                // At each index in array, make newPoint identical to our original px
                newPoint[i] = px[i];
            }
            // At index size, there should be nothing, so we can add string s there
            newPoint[sz] = s;
            //Increment size to update our new array size
            ++sz;
            //Reset the px pointer to point at the address of the newPoint pointer, newPointer is no longer pointing there
            px.reset(newPoint.release());
        }
        // If adding one to the size won't go over capacity variable
        else
        {
            //At index size, there shouldn't be anything, so we can add string s there
            px[sz] = s;
            //Increment size to update to our new array size
            ++sz;
        }
        
    }
    
    /**
     * Remove the last entry on our array of strings in our VectorString object.
     */
    void VectorString::pop_back()
    {
        //Reduce sz by one to chop off last part of array
        sz--;
    }
    
    /**
     * Delete an entry at a given index argument in our array of strings.
     * @param index The location in our array that we want to delete from
     */
    void VectorString::deleteAt(size_t index)
    {
        // Run for loop until we've gone through the entire size of our string array
        for (size_t i = index; i < sz-1; ++i)
        {
            // At index i, set the value of px[i] to the value following it
            px[i] = px[i+1];
        }
        //Now delete the last value of our array of strings
        pop_back();
     
        
    }
    
    /**
     * Add an entry at a given index argument in our array of strings.
     * @param index The location in our array that we want to insert at
     * @param s The string we want to insert into our array
     */
    void VectorString::insertAt(size_t index, const std::string& s)
    {
        
        //Push back last value in our array of strings
        push_back(px[sz - 1]);
        //Run for loop from the end of array all the way until index
        for (size_t i = sz; i > index; --i)
        {
            //Move everything at and greater than px[i] to value preceding it
            px[i] = px[i-1];
        }
        //At our given index we can now insert the string s
        px[index] = s;
    }
    
    
    /**
     * Return the string at a given index of our array
     * @param index The location in our array that we want to insert at
     * @return The string that lies in the index location of our array
     */
    std::string& VectorString::at(size_t index)
    {
        //Return string at the index of px
        return px[index];
    }
}




