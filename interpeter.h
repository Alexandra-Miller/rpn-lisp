#include <iostream>
#include <iterator> 
#include <map> 
#include <list>
#include <stdlib.h>


struct rlispNode {
    std::string data;
    rlispNode * next;
};


struct rlispList {
    rlispNode * head;
    rlispNode * tail;
    int size;
};


typedef void (*rlispFunction)(void);

class rlispInterpeter {
private:

    rlispNode * progCtr; // pointer to node being evaluated

    std::list< rlispNode * > callStack; // the call stack of the program
    std::list< std::string > dataStack; // the stack of strings in the program

    std::map< std::string, rlispList > usrSymTab;   // user defined symbol table
    std::map< std::string, rlispFunction > bltinSymTab; // builtin function symbol table



public:   
    interpeter.load( std::list< std::string > tokens )
    {
        
    }

    interpeter.step()
    {

        if( progHead->next )
        {
            // execute bltin or load data onto stack
            rlispFunction target = bltinSymTab.find( progHead->data );
            if( target != bltinSymTab.end() )
            {
                target();
            }


            else
            {
                dataStack.push_back( progHead->data );
            }

            progHead = progHead->next;
        }

        else
        {
            // execute bltin or load data onto stack
            rlispFunction target = bltinSymTab.find( progHead->data );
            if( target != bltinSymTab.end() )
            {
                target();
            }
            else
            {
                dataStack.push_back( progHead->data );
            }

            
            if( callStack.size() )
            {
                // exit function
                progCtr = callStack[0];
                callStac.pop_front();
            {
            else()
            {
                // exit program
                EXIT();
            }
        }
    }


    

    void ADD()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        this->dataStack.push_front( std::to_string( stod( val1.c_str() ) + stod( val0.c_str() ) ) )

        this->progCtr = this->progCtr->next;
    }

    void SUBTRACT()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        this->dataStack.push_front( std::to_string( stod( val0.c_str() ) - stod( val1.c_str() ) ) )

        this->progCtr = this->progCtr->next;
    }

    void MULTIPLY()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        this->dataStack.push_front( std::to_string( stod( val0.c_str() ) * stod( val1.c_str() ) ) )

        this->progCtr = this->progCtr->next;
    }

    void DIVIDE()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        this->dataStack.push_front( std::to_string( stod( val0.c_str() ) / stod( val1.c_str() ) ) )

        this->progCtr = this->progCtr->next;
    }

    void EXPONENTIATE()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        this->dataStack.push_front( std::to_string( pow( stod( val0.c_str() ), stod( val1.c_str() ) ) ) )

        this->progCtr = this->progCtr->next;
    }

    void ROOT()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        this->dataStack.push_front( 
                std::to_string( pow( stod( val0.c_str() ), 
                        ( 1.0 / stod( val1.c_str() ) ) ) ) )

        this->progCtr = this->progCtr->next;
    }

    void GREATER()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        if( val0 > val1 )
        {
            this->dataStack.push_front("T");
        }
        else
        {
            this->dataStack.push_back("F");
        }

        this->progCtr = this->progCtr->next;
    }

    void LESSER()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        if( val0 < val1 )
        {
            this->dataStack.push_front("T");
        }
        else
        {
            this->dataStack.push_back("F");
        }
    }

    void EQUAL()
    {
        std::string val1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string val0 = this->dataStack[0]->data;
        this->dataStack.pop_front();


        if( val0 == val1 )
        {
            this->dataStack.push_front( "T" )
        }
        else
        {
            this->dataStack.push_front( "F" )
        }

    }

    void OR()
    {
        std::string cond1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string cond0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        if( ( ( cond0 != "F" ) && ( cond0 != "false" ) ) || ( ( cond1 != "F" ) && ( cond1 != "false" ) ) )
        {
            this->dataStack.push_front( "T" )
        }
        else
        {
            this->dataStack.push_front( "F" )
        }

    }

    void AND()
    {
        std::string cond1 = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string cond0 = this->dataStack[0]->data;
        this->dataStack.pop_front();

        if( ( ( cond0 != "F" ) && ( cond0 != "false" ) ) && ( ( cond1 != "F" ) && ( cond1 != "false" ) ) )
        {
            this->dataStack.push_front( "T" )
        }
        else
        {
            this->dataStack.push_front( "F" )
        }

    }

    void NOT()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();

        if( ( cond != "F" ) && ( cond != "false" ) )
        {
            this->dataStack.push_front( "T" )
        }
        else
        {
            this->dataStack.push_front( "F" )
        }

    }


    // note, does not check if list is empty.
    void EVALUATE()
    {
        std::string sym = this->dataStack[0]->data;
        this->dataStack.pop_front();
        this->callStack.push_front( this->progCtr->next ); // push exit location onto call stack
        this->progCtr = this->usrSymTab.find( sym ).head;  // step into function
    }

    //
    void EVALUATE_IF()
    {
       
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();

        if( ( cond != "F" ) && ( cond != "false" ) )
        {
            this->progCtr = this->progCtr->next;
        }
        else
        {
            std::string sym = this->dataStack[0]->data;
            this->dataStack.pop_front();
            this->callStack.push_front( this->progCtr->next ); // push exit location onto call stack
            this->progCtr = this->usrSymTab.find( sym ).head;  // step into function
        }
    }
    
    // ==
    void CONCATENATE()
    {
        
        this->progCtr = this->progCtr->next;
    }

    // .=
    void HEAD()
    {
        std::string sym = this->dataStack[0];
        this->dataStack.pop_front();
        this->dataStack.push_front( this->usrSymTab.find( sym ).head );
        this->progCtr = this->progCtr->next;
    }

    // =.
    void TAIL()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
    }

    // +=
    void INSERT()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
    }

    // x=
    void DELETE()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
    }

    // ->
    void MOVE()
    {
        
    }

    // =]
    void REVERSE()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
    }

    // =s
    void SIZE()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
    }

    // =<
    void BIND()//ing of issac
    {
       this->usrSymTab

    }

    // >>
    void STDIN()
    {
        std::string strIn;
        std::cin >> strIn;
        this->dataStack.push_front(strIn);
    }

    // <<
    void STDOUT()
    {
        std::cout << this->dataStack[0]->data << std::endl;
        this->dataStack.pop_front();
    }

    // ||
    void STOP()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
    }

    // x|
    void EXIT()
    {
        std::string cond = this->dataStack[0]->data;
        this->dataStack.pop_front();
        
    }

};


