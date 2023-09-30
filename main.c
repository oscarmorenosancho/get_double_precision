/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoreno- <omoreno-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 11:06:14 by omoreno-          #+#    #+#             */
/*   Updated: 2023/09/30 13:53:57 by omoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <cmath>

int count_decimals(double e, int dig)
{
	double q;
	int count1=0;
	q=e;
	while(q!=(std::trunc(q)))
	{
		count1++;
		if (count1 + dig > 14)
			return count1;
		q*=10;
	}
	if (count1 < 1)
		return (1);
	return count1;
}

int count_non_decimals(double e)
{
	double q;
	int count1=0;
	if (e < 0)
		q = -e;
	else
		q = e;
	while(q>0.0)
	{
		count1++;
		if (count1 > 14)
			return (count1);
		q/=10;
		if (q < 1.0)
			q = 0;
	}
	return count1;
}

int get_precision(double e)
{
	int		n_decim = count_non_decimals(e);
	int		decim = count_decimals(e, n_decim);
	int prec = n_decim + decim;
	std::cout << "dig: " << n_decim << ", dec: " << decim << ", prec: " << prec << "\n";
	return (prec);
}

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		std::cerr << "Usage: " << argv[0] << " to_print" << std::endl;
		return (1);
	}
	try
	{
		double dV = std::stod(argv[1]);
		std::cout << std::setw(4) << std::setprecision(get_precision(dV)) << std::showpoint << dV << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
	}
	return 0;
}
