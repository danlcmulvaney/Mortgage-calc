#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Daniel Mulvaney

double compute_interest_total(double loanAmt, double interestRt, double term){
	
	int i;
	double fullInterest, fullInterest_total;
	double fullPayment = 0.0;
	double fullPayment_total = 0.0;
	double fullLoanAmt = loanAmt;
	int months = term * 12;
	int L = loanAmt;
	double m_rate = (interestRt / 12) / 100;
	double formula_power = pow((1 + m_rate), months);
	double P = (L * m_rate * formula_power) / (formula_power - 1);
	


	//calculates the interest total, and the total ammount that will be paid
	for (i = 0; i<months; i++){
		fullInterest = m_rate * fullLoanAmt;
		fullInterest_total += fullInterest;
		fullPayment = P - fullInterest;
		fullPayment_total += fullPayment;
		fullLoanAmt = fullLoanAmt - fullPayment;
	}
	
	//returns total
	return fullInterest_total;
	
}

void output_short_formula(double loanAmt, double interestRt, double term){
		
	printf("---------------------------------------\n");
	printf("             Loan Terms\n");
	printf("---------------------------------------\n");
	
	printf("Loan Amount: %25.0lf", loanAmt);
	printf("\n");
	printf("Interest Rate: %22.2lf \b%%", interestRt);
	printf("\n");
	printf("Term: %26.0lf years", term);
	printf("\n");
	
	printf("---------------------------------------\n\n\n");

	int i;
	double interest;
	double interest_total;
	double payment = 0.0;
	double payment_total = 0.0;
	int months = term * 12;
	int L = loanAmt;
	double m_rate = (interestRt / 12) / 100;
	double formula_power = pow((1 + m_rate), months);
	double P = (L * m_rate * formula_power) / (formula_power - 1);
	
	printf("Monthly payment is: %25.2lf", P);
	printf("\n");
	
	//calculates the interest total, and the total ammount that will be paid
	for (i = 0; i<months; i++){
		interest = m_rate * loanAmt;
		interest_total += interest;
		payment = P - interest;
		payment_total += payment;
		loanAmt = loanAmt - payment;
	}
	
	printf("Total interest is: %26.2lf", interest_total);
	printf("\n");
	
	printf("Total amount paid is: %23.2lf", payment_total + interest_total);
	printf("\n\n\n");
	
}

void output_amortized(double loanAmt, double interestRt, double term){
	
	int i, j;
	double interest;
	double interest_total;
	double payment = 0.0;
	double payment_total = 0.0;
	int months = term * 12;
	
	//counters to keep track of the year and month
	int countMonth = 0;
	int countYear = 0;
	

	int L = loanAmt;
	double m_rate = (interestRt / 12) / 100;
	double formula_power = pow((1 + m_rate), months);
	double P = (L * m_rate * formula_power) / (formula_power - 1);
	
	//while loop to calculate and print out the following output
	while (loanAmt > 0){
		
		interest = m_rate * loanAmt;
		interest_total += interest;
		payment = P - interest;
		payment_total += payment;
		loanAmt = loanAmt - payment;
	
		if (loanAmt <= 0)
			break;
			
		//start of a new year
		if (countMonth % 12 == 0){
		
			countMonth++;
		
			countYear++;
		
			//start of a new year, print out this header
			printf("\n\n-----------------------------------------------------------------\n");
			printf("Year  Month  Interest  Principal  Balance  |  INTEREST PRINCIPAL\n");
			printf("-----------------------------------------------------------------\n");
		
			//formatting
			if (countYear < 10)
				printf(" ");
	
			printf("%d", countYear);
		
			//formatting
			printf("%8d", countMonth);
			printf("%7.0lf", interest);
			printf("%9.0lf", payment);
			printf("%14.0lf", loanAmt);
			printf("   |");
			printf("%9.0lf", interest_total);
			printf("%12.0lf", payment_total);
			printf("\n");
		
		}
	
		else{
	
			countMonth++;
		
			//formatting		
			printf("%10d", countMonth);
			printf("%7.0lf", interest);
			printf("%9.0lf", payment);
			printf("%14.0lf", loanAmt);
			printf("   |");
			printf("%9.0lf", interest_total);
			printf("%12.0lf", payment_total);
			printf("\n");
			
		}
		
		
		
	}
	
	printf("\n\n");

}

void output_extra_monthly(double loanAmt, double interestRt, double term, double extra){
	
	int i;
	float year;
	
	//counters to keep track of the year and month
	int countMonth = 0;
	int countYear = 0;
	
	double fullInterest_total = compute_interest_total(loanAmt, interestRt, term);
	double interest;
	double interest_total;
	double payment = 0.0;
	double payment_total = 0.0;
	int months = term * 12;
	int L = loanAmt;
	
	double m_rate = (interestRt / 12) / 100;
	double formula_power = pow((1 + m_rate), months);
	double P = (L * m_rate * formula_power) / (formula_power - 1);


	//calculate and output 'extra' monthly payments
	do{
		
		
		interest = m_rate * loanAmt;
		interest_total += interest;
		payment = P - interest;
		payment_total += payment + extra;
		loanAmt = loanAmt - extra - payment;
			
		//start of a new year, print this
		if (countMonth % 12 == 0){
		
			countMonth++;
			
			countYear++;
		
			printf("\n\n---------------------------------------------------------------------\n");
			printf("Year  Month  Interest  Principal  Balance  |  INTEREST PRINCIPAL EXTRA\n");
			printf("---------------------------------------------------------------------\n");

			//formatting
			if (countYear < 10)
				printf(" ");
				printf("%d", countYear);
		
			//formatting
			printf("%8d", countMonth);
			printf("%7.0lf", interest);
			printf("%9.0lf", payment);
			printf("%14.0lf", loanAmt);
			printf("   |");
			printf("%9.0lf", interest_total);
			printf("%14.0lf", payment_total);
			printf("%7.0lf", extra);
			printf("\n");
		
		
		}
		
		
		else{
			
			countMonth++;
			
			//formatting
			printf("%10d", countMonth);
			printf("%7.0lf", interest);
			printf("%9.0lf", payment);
			printf("%14.0lf", loanAmt);
			printf("   |");
			printf("%9.0lf", interest_total);
			printf("%14.0lf", payment_total);
			printf("%7.0lf", extra);
			printf("\n");
				

		}
	
		//end of the calculations	
		if (loanAmt <= 0){
			
			//find the amount of years saved
			year = (months - countMonth) / 12.0;
		
			//print the number of months and years saved
			printf ("\nThe payments are finished %d months in advanced! (%.2f years)\n", (months - countMonth), year);
		
			//calculate the interest saving from the calculated full interest
			printf ("The interest saving is %.2lf", fullInterest_total - interest_total);
			printf("\n\n");
			break;
		}
		
	} while(loanAmt > 0);
		

	printf("\n\n");

}

void output_extra_yearly(double loanAmt, double interestRt, double term, double extra){
	
	int i;
	float year;
	
	//counters to keep track of the year and month
	int countMonth = 0;
	int countYear = 0;
	
	double fullInterest_total = compute_interest_total(loanAmt, interestRt, term);
	double interest;
	double interest_total;
	double payment = 0.0;
	double payment_total = 0.0;
	int months = term * 12;

	int L = loanAmt;
	double m_rate = (interestRt / 12) / 100;
	double formula_power = pow((1 + m_rate), months);
	double P = (L * m_rate * formula_power) / (formula_power - 1);	

	//calculate and output 'extra' yearly payments
	do{
			
		interest = m_rate * loanAmt;
		interest_total += interest;
		payment = P - interest;
		countMonth++;	
	
		//if december, calculate the forumula with the extra payment
		if (countMonth % 12 == 0){
			payment_total = payment_total + payment + extra;
			loanAmt = loanAmt - extra - payment;
		}
	
		//calculate without extra payment		
		else{
			payment_total += payment;
			loanAmt = loanAmt - payment;	
		}
	
		//start of a new year, print out this header	
		if (countMonth % 12 == 1){
		
		
			countYear++;
		
			printf("\n\n---------------------------------------------------------------------\n");
			printf("Year  Month  Interest  Principal  Balance  |  INTEREST PRINCIPAL EXTRA\n");
			printf("---------------------------------------------------------------------\n");


			//formatting
			if (countYear < 10)
				printf(" ");
			printf("%d", countYear);
		
			//formatting
			printf("%8d", countMonth);
			printf("%7.0lf", interest);
			printf("%9.0lf", payment);
			printf("%14.0lf", loanAmt);
			printf("   |");
			printf("%9.0lf", interest_total);
			printf("%14.0lf", payment_total);
			printf("\n");
		
		
		}
			
		else{
			
			//formatting	
			printf("%10d", countMonth);
			printf("%7.0lf", interest);
			printf("%9.0lf", payment);
			printf("%14.0lf", loanAmt);
			printf("   |");
			printf("%9.0lf", interest_total);
			printf("%14.0lf", payment_total);
		
			//if december, print out the extra payment	
			if (countMonth % 12 == 0)
				printf("%7.0lf", extra);
				
			printf("\n");
				
	}
		
		//end of the calculations		
		if (loanAmt <= 0){
		
			//find the amount of years saved
			year = (months - countMonth) / 12.0;
		
			//print the number of months and years saved
			printf ("\nThe payments are finished %d months in advanced! (%.2f years)\n", (months - countMonth), year);
		
			//calculate the interest saving from the calculated full interest
			printf ("The interest saving is %.2lf", fullInterest_total - interest_total);
			printf("\n\n");
			break;
		}
		

	} while (loanAmt > 0);
	
	printf("\n\n");
}
