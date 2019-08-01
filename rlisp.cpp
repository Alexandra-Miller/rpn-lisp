#include <iostream>



int main ( int argc , char *argv[] )
{
    std::string parseTarget;
    rlispInterpeter Interpeter;
    if(argc > 2)
    {
        std::cout << "ERROR, INVALID INPUT PATTERN" << std::endl;
        exit 0;
    }

    else if( argc = 2 )
    {
        parseTarget = getFile( argv[1] );
    
        interpeter.load( parser ( parseTarget ) )
        while( interpeter.exit() )
        {
            interpeter.step()
        }
    }

    else
    {
        std::cout << "ERROR, INPUT FILE UNSPECIFIED" << std::cout;
        /*
        while( true )
        {
            std::cin >> target;
            
            while( ! interpeter.exit() )
        }
        */
    }
}



