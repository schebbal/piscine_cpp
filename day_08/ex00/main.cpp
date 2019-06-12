/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.cpp                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/11 09:30:44 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/11 11:06:38 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include <iomanip> 
#include "easyfind.hpp"

void    firstOccur(int val, std::list<int> *lst)
{    
    try
    {
        std::cout << std::setw(5) << std::left << val << " -> ";
        easyfind<std::list<int> > (*lst, val);
    }
    catch (std::string str)
    {
        std::cout << str << std::endl;
    }
}

int main(void)
{
    std::list<int>    lst;

    lst.push_back(18);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(25);
    lst.push_back(101);
    lst.push_back(42);

    firstOccur(1, &lst);
    firstOccur(18, &lst);
    firstOccur(25, &lst);
    firstOccur(29, &lst);
    firstOccur(101, &lst);
    firstOccur(30, &lst);
    firstOccur(42, &lst);
    
    return (0);
}