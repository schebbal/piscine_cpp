/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 16:27:39 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/12 14:50:11 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include "mutantstack.hpp"

int main() {
    MutantStack<int>    mstack; 
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl;
    
    mstack.pop();
    
    std::cout << mstack.size() << std::endl;
    
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    
    mstack.push(0);
    
    MutantStack<int>::iterator      it = mstack.begin(); 
    MutantStack<int>::iterator      ite = mstack.end();
    
    ++it;
    --it;
    
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it; 
    }
    std::stack<int>     s(mstack);
    
    return 0; 
}
