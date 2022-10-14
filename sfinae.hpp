#pragma once

namespace ft
{

	//////////////////////////////////////////////////////////////
	/*									                        */
	/*						Enable_if	                        */
	/*									                        */
	//////////////////////////////////////////////////////////////

    template <bool B, class T = void>
    struct enable_if;

    template<class T> 
    struct enable_if<true, T> 
    {
        typedef T type;
    };
    

    


}