/**********************************************
Function to check whether braces (paranthesis, square brackets and 
curly braces) are balanced in multiple statements. 
The statements are passed into the function as a vector of strings,
and a vector of strings is returned with respective indices containing
either a YES or NO depending on whether the statements are balanced 
within the corresponding string vector.

An example of a balanced string would be 
{[()]}[]()

whereas an example of an invalid one would be
{([)]}
**********************************************/

vector<string> braces(vector<string> values) {

    vector<string> braces;
    
    for (int i = 0; i < values.size(); i++){
        //primary check to ensure there are equal number of braces in the string
        int lParan = 0, rParan = 0, lSquare = 0, rSquare = 0, lBrace = 0, rBrace = 0;
        
        //hold the string
        string str = values[i];
        
        //get the count for each type of brace
        for (int j = 0; j < str.size(); j++){
            if (str[j] == '(') lParan++;
            else if (str[j] == ')') rParan++;
            else if (str[j] == '[') lSquare++;
            else if (str[j] == ']') rSquare++;
            else if (str[j] == '{') lBrace++;
            else rBrace++;
        }   //end inner for
        
        //check if any of the braces are unmatched
        if (lParan != rParan && lSquare != rSquare && lBrace != rBrace)
            braces.push_back("NO");
        
        else{
            stack<char> paran;  //to hold the order of the braces
            bool flag = true;   //check for the for loop
            
            //checking the order of the braces
            for (int j = 0; j < str.size(); j++ && flag == true){
                
                char temp;  //temporary char var to hold part of the string
                
                //adding all the left braces in order they appear in the string
                if (str[j] == '{' || str[j] == '[' || str[j] == '('){
                    paran.push(str[j]);
                    continue;   //jump to end of for loop
                }
                
                //there are not left/opening braces in the string
                if (paran.empty()) 
                    flag == false; //change the for loop condition
                
                //not an empty stack, now we are left with all right/closing braces
                else{
                    if (str[j] == '}'){
                        temp = paran.top();
                        paran.pop();
                        //ensure that the curly brace matches its counterpart
                        if (temp == '[' || temp == '(') flag = false;
                    }   //end if

                    else if (str[j] == ']'){
                        temp = paran.top();
                        paran.pop();
                        //ensure that the square bracket matches its counterpart
                        if (temp == '{' || temp == '(') flag = false;
                    }   //end else if

                    else{
                        temp = paran.top();
                        paran.pop();
                        //ensure that the parathesis matches its counterpart
                        if (temp == '{' || temp == '[') flag = false;
                    }   //end else
                }   //end outer else
            }   //end inner for
            
            //Unbalanced Braces
            if (!flag) braces.push_back("NO");
            
            //balanced Braces
            else braces.push_back("YES");
        }   //end outer else
    }   //end for
    
    return(braces);

}

