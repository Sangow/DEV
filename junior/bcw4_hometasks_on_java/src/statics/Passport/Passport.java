package statics.Passport;

class PassportException extends Exception {
    public PassportException(String message) {
        super(message);
    }
}

public class Passport {
    private static char[] lastSerial = {'A', 'A'};
    private static int lastNumber = 0;

    private String  name;
    private String  surname;
    private String  serial;
    private int     number;
    private Date    date;

    private void validNextSN() throws PassportException {
        if ( lastNumber < 999999 ) {
            lastNumber += 1;
        } else if ( lastSerial[0] == 'Z' && lastSerial[1] == 'Z' ) {
            throw new PassportException("Max passport amount was reached!");
        } else if ( lastSerial[1] == 'Z' ) {
            lastSerial[0] += 1;
            lastSerial[1] = 'A';
            lastNumber = 1;
        } else {
            lastSerial[1] += 1;
            lastNumber = 1;
        }
    }

    public Passport(String name, String surname, Date date) throws PassportException {
        this.validNextSN();

        this.date = date;
        this.name = name;
        this.surname = surname;
        this.serial = String.valueOf(lastSerial);
        this.number = lastNumber;
    }

    public void setSN(String newSerial) throws PassportException {
        if ( newSerial.length() > 2 ) {
            throw new PassportException("Invalid serial size!");
        }
        if ( !Character.isUpperCase(newSerial.charAt(0)) || !Character.isUpperCase(serial.charAt(1)) ) {
            throw new PassportException("Invalid serial format!");
        }

        lastSerial = newSerial.toCharArray();
        lastNumber = 0;
    }

    public void setSN(String newSerial, int newNumber) throws PassportException {
        if ( newNumber < 1 || newNumber > 999999 ) {
            throw new PassportException("Number is out of range!");
        }

        this.setSN(newSerial);
        lastNumber = newNumber - 1;
    }

    @Override
    public String toString() {
        return String.format("Name:\t\t\t" + this.name + "\n"
                            + "Surname:\t\t" + this.surname + "\n"
                            + "S/N:\t\t\t" + this.serial + " " + String.format("%06d", this.number) + "\n"
                            + "Date of birth:\t" + this.date);
    }
}
