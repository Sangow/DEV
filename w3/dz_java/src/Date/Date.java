package Date;

public class Date {
    private int day;
    private int month;
    private int year;

    private void validate(int day, int month, int year) throws InvalidDate {
        boolean isLeap = false;

        if (this.year % 4 == 0 && (this.year % 100 != 0 || this.year % 400 == 0)) {
            isLeap = true;

            if (this.day < 1 || this.day > 31) {
                throw new InvalidDate("Invalid day!");
            }

            if (this.month < 1 || this.month > 12) {
                throw new InvalidDate("Invalid month");
            }

            if ( this.month == 2 && this.day > 28 && !isLeap ) {
                throw new InvalidDate("Invalid day in nonLeap February!");
            }

            if ( this.month == 2 && this.day > 29 && isLeap ) {
                throw new InvalidDate("Invalid day in leap February!");
            }

            if ( ( this.month == 4 || this.month == 6 || this.month == 9 || this.month == 11 ) && this.day > 30 ) {
                throw new InvalidDate("Invalid day in 30Day month!");
            }
        }
    }
}
