/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   Account.class.cpp                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: schebbal <schebbal@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/04/01 16:05:22 by schebbal     #+#   ##    ##    #+#       */
/*   Updated: 2019/04/02 15:28:08 by schebbal    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp" 

#include <stdio.h>      /* puts */
#include <time.h>       /* time_t, struct tm, time, localtime, strftime */

void    Account::_displayTimestamp()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [128];

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (buffer, 128, "%Y%m%d_%H%M%S", timeinfo);
    std::cout << "[" << buffer << "] ";
}

Account::Account( int initial_deposit )
{
    this->_nbAccounts = this->_nbAccounts + 1;
	this->_totalAmount = this->_totalAmount + initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << (this->_accountIndex - 1) <<
		";amount:" << this->_amount << ";created" << std::endl;
}

Account::~Account (void)
{
	Account::_displayTimestamp();
    std::cout   << "index:" << (this->_accountIndex - 1) 
                << ";amount:" << this->_amount 
                << ";closed" << std::endl;
}

void    Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
    std::cout   << "accounts:" << Account::_nbAccounts 
                << ";total:" << Account::_totalAmount
                << ";deposits:" << Account::_totalNbDeposits
                << ";withdrawals:" << Account::_totalNbWithdrawals
                << std::endl;
    return ;
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout   << "index:" << (this->_accountIndex - 1) 
                << ";amount:" << this->_amount 
                << ";deposits:" << this->_nbDeposits 
                << ";withdrawals:" << this->_nbWithdrawals 
                << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    this->_amount = this->_amount + deposit;
    this->_nbDeposits = this->_nbDeposits + 1;
	this->_totalAmount = this->_totalAmount + deposit;
	this->_totalNbDeposits = this->_totalNbDeposits + 1;

    Account::_displayTimestamp();
    std::cout   << "index:" << (this->_accountIndex - 1) 
                << ";p_amount:" << (this->_amount - deposit) 
                << ";deposit:" << deposit 
                << ";amount:" << this->_amount 
                << ";nb_deposits:" << this->_nbDeposits 
                << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    if (this->_amount < withdrawal)
	{
        Account::_displayTimestamp();
        std::cout   << "index:" << (this->_accountIndex - 1) 
                    << ";p_amount:" << this->_amount 
                    <<  ";withdrawal:" << "refused" 
                    << std::endl;
        return (false);
    } else {
        this->_totalAmount = this->_totalAmount - withdrawal;
		this->_totalNbWithdrawals = this->_totalNbWithdrawals + 1;
		this->_amount = this->_amount - withdrawal;
		this->_nbWithdrawals = this->_nbWithdrawals + 1;

        Account::_displayTimestamp();
        std::cout   << "index:" << (this->_accountIndex - 1) 
                    << ";p_amount:" << (this->_amount + withdrawal) 
                    <<  ";withdrawal:" << withdrawal 
                    << ";amount:" << this->_amount 
                    << ";nb_withdrawals:" << this->_nbWithdrawals 
                    << std::endl;
        return (true);
    }
}

int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;