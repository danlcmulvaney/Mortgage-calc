#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Daniel Mulvaney

int main(){
	int input;
	double loanAmt, interestRt, term, extra;
	
	
	//initial values
	printf("Loan Amount: ");
	scanf("%lf", &loanAmt);
	printf("Interest Rate: ");
	scanf("%lf", &interestRt);
	printf("Term (In years): ");
	scanf("%lf", &term);
	printf("\n\n");


	//Menu options
	while (input != -1){
		
		printf("Mortgage Calculator (1: short format  2: amortized schedule  3: Extra Payments monthly  4: Extra Payments yearly)\n\n");
		printf ("Enter which calculator you would like to use (-1 to end calculations):\n");
		scanf("%d", &input);
		system("cls");
		
		//ends program
		if (input == -1)
			break;
			
		//calls short output
		else if (input == 1)
			output_short_formula(loanAmt, interestRt, term);
		
		//calls amortized output	
		else if (input == 2)
			output_amortized(loanAmt, interestRt, term);
			
		//asks for 'extra' ammount, inputs into function to produce output
		else if (input == 3){
			printf("Enter the extra payment amount input monthly: ");
			scanf("%lf", &extra);
			output_extra_monthly(loanAmt, interestRt, term, extra);
		}
		
		//asks for 'extra' ammount, inputs into function to produce output
		else if (input == 4){
			printf("Enter the extra payment amount input yearly: ");
			scanf("%lf", &extra);
			output_extra_yearly(loanAmt, interestRt, term, extra);
		}
			

	}
	
	return 0;
	
}

