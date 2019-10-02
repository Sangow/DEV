package statics.Passport;

class InvalidDate extends Exception {
    public InvalidDate(String message) {
        super(message);
    }
}

public class Date {
    private int day, month, year;

    private void validDate(int day, int month, int year) throws InvalidDate {
        boolean isLeap = false;

        if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) ) {
            isLeap = true;
        }

        if ( day < 1 || day > 31 ) {
            throw new InvalidDate("Invalid day!");
        }

        if ( month < 1 || month > 12 ) {
            throw new InvalidDate("Invalid month!");
        }

        if ( month == 2 && day > 28 && !isLeap ) {
            throw new InvalidDate("Invalid day in nonLeap February!");
        }

        if ( month == 2 && day > 29 && isLeap ) {
            throw new InvalidDate("Invalid day in leap February!");
        }

        if ( (month == 4 || month == 6 || month == 9 || month == 11) && day > 30 ) {
            throw new InvalidDate("Invalid day in 30Day month!");
        }
    }

    public Date () {
        this.day = 1;
        this.month = 1;
        this.year = 1970;
    }

    public Date(int day, int month, int year) throws InvalidDate {
        this.validDate(day, month, year);

        this.day = day;
        this.month = month;
        this.year = year;
    }

    @Override
    public String toString() {
        return String.format("%02d/%02d/%04d", this.day, this.month, this.year);
    }
}
