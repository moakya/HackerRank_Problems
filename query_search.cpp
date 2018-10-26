/*********************************************************************
Functions to check whether a vector of strings called sentences
contains matches from the vector of strings queries perfectly.

For example:
Sentences could contain:
"Hello there. I am a C++ Program."
"C++ is a good programming language, so is Java."

Queries could contain:
"C++"
"C++ Java"
"Python"

Using this example the output vector would be:

0, 1
1
-1

The numbers represent indicies in the sentences vector to indicate 
what sentence contains the matches for the queries. 
The indices in the final output vector would be the same as the query
indices to indicate the matches. -1 would indicate that there were no 
matches. If there are multiple queries in one index, then we treat it
as an AND condition as in we have to ensure that a sentence contains
all the words listed in the query.
*********************************************************************/

bool present(vector<string> words, vector<string> sentence){
    
    //will contain bool values depending on whether a match was found
    vector<bool> found;
    found.resize(words.size());
    
    //assuming no matches are found
    for(int i = 0; i < found.size(); i++)
        found[i] = false;
    
    //go through the sentence and determine whether match exists
    for(int i = 0; i < words.size(); i++)
        for (int j = 0; j < sentence.size(); j++)
            if (words[i] == sentence[j])
                found[i] = true;
    
    //if even a single bool value is false, this means there isnt a perfect match
    for(int i = 0; i < found.size(); i++)
        if (found[i] == false)
            return false;
    
    //perfec match was found
    return true;
}   //end present

void textQueries(vector<string> sentences, vector<string> queries) {
    
    //to hold the matches
    vector<vector<int>> matches;

    for (int i = 0; i < queries.size(); i++){
        
        matches.push_back(vector<int>());
        
        stringstream sstr(queries[i]);  //add current query to stringstream
        vector<string> phrases; //create vector of strings to hold phrases separately
        string temp;    //temporary var to hold the separated phrase
        
        //separate the query by spaces
        while(getline(sstr, temp, ' '))
            phrases.push_back(temp);    //add temp to the vector of phrases
        
        //getting all the words of the sentences vector into a 2d string vector
        //to separate the words in each sentences
        vector<vector<string>> words;   //to hold the word of a sentence separately
        for (int j = 0; j < sentences.size(); j++){
            words.push_back(vector<string>());
            stringstream nsstr(sentences[j]);
            string x;
            while(getline(nsstr, x, ' '))
                words[j].push_back(x);    //add temp to the vector of phrases
        }   //end inner for
       
        //pass each vector of the 2d string vector to a different function to find matches
        for (int j = 0; j < words.size(); j++)
            if (present(phrases, words[j]))
                matches[i].push_back(j);
    }
    
    //if there was a match found the sub vector won't be empty
    for (int m = 0; m < matches.size(); m++){
        if (matches[m].empty())
                cout << (-1);   //no matches
        else 
            for (int n = 0; n < matches[m].size(); n++)
                cout << matches[m][n] << " ";   //matches
        cout << endl;
    }   //end outer for
}   //end textQueries

