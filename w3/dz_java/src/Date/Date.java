public class Date {
    private int day;
    private int month;
    private int year;

    private void validate(int day, int month, int year) throws InvalidDate {
        boolean isLeap = false;

        if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) ) {
            isLeap = true;
        }

        if ( day < 1 || day > 31 ) {
            throw new InvalidDate("Invalid day!");
        }

        if ( month < 1 || month > 12 ) {
            throw new InvalidDate("Invalid month");
        }

        if ( month == 2 && day > 28 && !isLeap ) {
            throw new InvalidDate("Invalid day in nonLeap February!");
        }

        if ( month == 2 && day > 29 && isLeap ) {
            throw new InvalidDate("Invalid day in leap February!");
        }

        if ( ( month == 4 || month == 6 || month == 9 || month == 11 ) && day > 30 ) {
            throw new InvalidDate("Invalid day in 30Day month!");
        }
    }

    public Date() throws InvalidDate {
        this.day = 1;
        this.month = 1;
        this.year = 1970;
        this.validate(day, month, year);
    }

    public Date(int day, int month, int year) throws InvalidDate {
        this.validate(day, month, year);
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public int getDay() {
        return day;
    }

    public int getMonth() {
        return month;
    }

    public int getYear() {
        return year;
    }

    public String toString() {
        return String.format("Date: " + this.getDay() + "." + this.getMonth() + "." + this.getYear());
    }
}