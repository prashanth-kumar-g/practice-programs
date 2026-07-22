import java.io.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class PetCareScheduler {

    private static final String DATA_FILE = "petcare_data.ser";

    private static final DateTimeFormatter DATE_FORMATTER = DateTimeFormatter.ofPattern("dd-MM-yyyy");
    private static final DateTimeFormatter DISPLAY_DATE_TIME_FORMATTER = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm");
    private static final DateTimeFormatter INPUT_DASH_FORMATTER = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm");
    private static final DateTimeFormatter INPUT_SLASH_FORMATTER = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
    private static final DateTimeFormatter INPUT_COLON_FORMATTER = DateTimeFormatter.ofPattern("dd:MM:yyyy HH:mm");

    private static List<Pet> pets = new ArrayList<>();
    private static final Map<String, Pet> petMap = new HashMap<>();
    private static final Set<String> petIds = new HashSet<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        loadData();
        rebuildIndex();

        while (true) {
            showMainMenu();
            int choice = readInt(sc, "\n Enter your choice : ");

            switch (choice) {
                case 1:
                    registerPet(sc);
                    break;
                case 2:
                    scheduleAppointment(sc);
                    break;
                case 3:
                    displayDataMenu(sc);
                    break;
                case 4:
                    updateMenu(sc);
                    break;
                case 5:
                    deleteMenu(sc);
                    break;
                case 6:
                    saveData();
                    System.out.println("\n Data saved successfully. \n");
                    break;
                case 7:
                    exitProgram(sc);
                    sc.close();
                    return;
                default:
                    System.out.println("\n Invalid Choice, Select again. \n");
            }
        }
    }

    private static void showMainMenu() {
        System.out.println("\n====================================================================");
        System.out.println("                       PETCARE SCHEDULER MENU                       ");
        System.out.println("                      ========================                       ");
        System.out.println("\n   1) Register Pet   2) Schedule Appointment   3) Display Data     ");
        System.out.println("\n   4) Update         5) Delete       6) Save   7) Exit            ");
        System.out.println("\n====================================================================");
    }

    private static void displayDataMenu(Scanner sc) {
        while (true) {
            System.out.println("\n--------------------------------------------------------------------");
            System.out.println("                         DISPLAY DATA MENU                          ");
            System.out.println("                      --------------------------------              ");
            System.out.println("   1) All registered pets                                           ");
            System.out.println("   2) All appointments for a specific pet                           ");
            System.out.println("   3) Upcoming appointments for all pets                            ");
            System.out.println("   4) Past appointment history for each pet                         ");
            System.out.println("   5) Back                                                          ");
            System.out.println("--------------------------------------------------------------------");

            int choice = readInt(sc, "\n Enter your choice : ");

            switch (choice) {
                case 1:
                    displayAllPets();
                    break;
                case 2:
                    displayAppointmentsForSpecificPet(sc);
                    break;
                case 3:
                    displayUpcomingAppointments();
                    break;
                case 4:
                    displayPastAppointmentHistory();
                    break;
                case 5:
                    return;
                default:
                    System.out.println("\n Invalid Choice, Select again. \n");
            }
        }
    }

    private static void updateMenu(Scanner sc) {
        while (true) {
            System.out.println("\n--------------------------------------------------------------------");
            System.out.println("                           UPDATE MENU                               ");
            System.out.println("                      --------------------------------              ");
            System.out.println("   1) Update Pet Details                                            ");
            System.out.println("   2) Update Appointments by Pet ID                                 ");
            System.out.println("   3) Back                                                          ");
            System.out.println("--------------------------------------------------------------------");

            int choice = readInt(sc, "\n Enter your choice : ");

            switch (choice) {
                case 1:
                    updatePetDetails(sc);
                    break;
                case 2:
                    updateAppointmentByPetId(sc);
                    break;
                case 3:
                    return;
                default:
                    System.out.println("\n Invalid Choice, Select again. \n");
            }
        }
    }

    private static void deleteMenu(Scanner sc) {
        while (true) {
            System.out.println("\n--------------------------------------------------------------------");
            System.out.println("                           DELETE MENU                               ");
            System.out.println("                      --------------------------------              ");
            System.out.println("   1) Delete Pet                                                    ");
            System.out.println("   2) Delete Appointment by Pet ID                                  ");
            System.out.println("   3) Back                                                          ");
            System.out.println("--------------------------------------------------------------------");

            int choice = readInt(sc, "\n Enter your choice : ");

            switch (choice) {
                case 1:
                    deletePet(sc);
                    break;
                case 2:
                    deleteAppointmentByPetId(sc);
                    break;
                case 3:
                    return;
                default:
                    System.out.println("\n Invalid Choice, Select again. \n");
            }
        }
    }

    private static void registerPet(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                           REGISTER PET                              ");
        System.out.println("--------------------------------------------------------------------");

        try {
            String petId = readNonEmpty(sc, "\n Enter Pet ID : ");
            if (petIdExists(petId)) {
                System.out.println("\n The Pet ID already exists. Registration cancelled. \n");
                return;
            }

            String name = readNonEmpty(sc, " Enter Name : ");
            String speciesBreed = readNonEmpty(sc, " Enter Species/Breed : ");
            int age = readPositiveInt(sc, " Enter Age : ");
            String ownerName = readNonEmpty(sc, " Enter Owner Name : ");
            String contactInfo = readNonEmpty(sc, " Enter Contact Info : ");

            Pet pet = new Pet(
                    petId,
                    name,
                    speciesBreed,
                    age,
                    ownerName,
                    contactInfo,
                    LocalDate.now()
            );

            pets.add(pet);
            petMap.put(petId, pet);
            petIds.add(petId);

            System.out.println("\n The Pet is Registered Successfully. \n");
        } catch (Exception e) {
            System.out.println("\n Error while registering pet : " + e.getMessage() + "\n");
        }
    }

    private static void scheduleAppointment(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                        SCHEDULE APPOINTMENT                        ");
        System.out.println("--------------------------------------------------------------------");

        try {
            if (pets.isEmpty()) {
                System.out.println("\n No pets registered. \n");
                return;
            }

            String petId = readNonEmpty(sc, "\n Enter Pet ID : ");
            Pet pet = findPetById(petId);

            if (pet == null) {
                System.out.println("\n Pet ID not found. \n");
                return;
            }

            String type = readNonEmpty(sc, " Enter Appointment Type : ");
            String dateText = readNonEmpty(sc, " Enter Date and Time (dd-MM-yyyy HH:mm) : ");
            LocalDateTime dateTime = parseDateTimeFlexible(dateText);

            System.out.print(" Enter Notes (optional) : ");
            String notes = sc.nextLine().trim();

            Appointment appointment = new Appointment(type, dateTime, notes);
            pet.addAppointment(appointment);

            System.out.println("\n The Appointment is Scheduled Successfully. \n");
        } catch (Exception e) {
            System.out.println("\n Error while scheduling appointment : " + e.getMessage() + "\n");
        }
    }

    private static void displayAllPets() {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                         ALL REGISTERED PETS                        ");
        System.out.println("--------------------------------------------------------------------");

        if (pets.isEmpty()) {
            System.out.println("\n No pets registered. \n");
            return;
        }

        String[] headers = {
                "Pet ID", "Name", "Species/Breed", "Age",
                "Owner Name", "Contact Info", "Registration Date", "Appts"
        };

        int[] widths = {10, 16, 18, 5, 16, 16, 16, 7};

        List<String[]> rows = new ArrayList<>();
        for (Pet pet : pets) {
            rows.add(new String[] {
                    pet.getPetId(),
                    pet.getName(),
                    pet.getSpeciesBreed(),
                    String.valueOf(pet.getAge()),
                    pet.getOwnerName(),
                    pet.getContactInfo(),
                    formatDate(pet.getRegistrationDate()),
                    String.valueOf(pet.getAppointments().size())
            });
        }

        printTable(headers, rows, widths);
    }

    private static void displayAppointmentsForSpecificPet(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                   ALL APPOINTMENTS FOR A SPECIFIC PET              ");
        System.out.println("--------------------------------------------------------------------");

        String petId = readNonEmpty(sc, "\n Enter Pet ID : ");
        Pet pet = findPetById(petId);

        if (pet == null) {
            System.out.println("\n Pet ID not found. \n");
            return;
        }

        if (pet.getAppointments().isEmpty()) {
            System.out.println("\n No appointments found for this pet. \n");
            return;
        }

        String[] headers = { "No", "Appointment Type", "Date and Time", "Notes" };
        int[] widths = { 4, 22, 20, 32 };

        List<String[]> rows = new ArrayList<>();
        int i = 1;
        for (Appointment a : pet.getAppointments()) {
            rows.add(new String[] {
                    String.valueOf(i++),
                    a.getAppointmentType(),
                    formatDateTime(a.getDateTime()),
                    a.getNotes() == null || a.getNotes().isBlank() ? "N/A" : a.getNotes()
            });
        }

        System.out.println("\n Pet ID     : " + pet.getPetId());
        System.out.println(" Pet Name   : " + pet.getName());
        System.out.println(" Owner Name : " + pet.getOwnerName());
        System.out.println();
        printTable(headers, rows, widths);
    }

    private static void displayUpcomingAppointments() {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                    UPCOMING APPOINTMENTS FOR ALL PETS              ");
        System.out.println("--------------------------------------------------------------------");

        LocalDateTime now = LocalDateTime.now();
        List<String[]> rows = new ArrayList<>();

        for (Pet pet : pets) {
            for (Appointment a : pet.getAppointments()) {
                if (a.getDateTime().isAfter(now)) {
                    rows.add(new String[] {
                            pet.getPetId(),
                            pet.getName(),
                            a.getAppointmentType(),
                            formatDateTime(a.getDateTime()),
                            a.getNotes() == null || a.getNotes().isBlank() ? "N/A" : a.getNotes()
                    });
                }
            }
        }

        String[] headers = { "Pet ID", "Pet Name", "Type", "Date and Time", "Notes" };
        int[] widths = { 10, 16, 18, 20, 28 };

        if (rows.isEmpty()) {
            System.out.println("\n No upcoming appointments found. \n");
            return;
        }

        printTable(headers, rows, widths);
    }

    private static void displayPastAppointmentHistory() {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                      PAST APPOINTMENT HISTORY                      ");
        System.out.println("--------------------------------------------------------------------");

        LocalDateTime now = LocalDateTime.now();
        List<String[]> rows = new ArrayList<>();

        for (Pet pet : pets) {
            for (Appointment a : pet.getAppointments()) {
                if (a.getDateTime().isBefore(now)) {
                    rows.add(new String[] {
                            pet.getPetId(),
                            pet.getName(),
                            a.getAppointmentType(),
                            formatDateTime(a.getDateTime()),
                            a.getNotes() == null || a.getNotes().isBlank() ? "N/A" : a.getNotes()
                    });
                }
            }
        }

        String[] headers = { "Pet ID", "Pet Name", "Type", "Date and Time", "Notes" };
        int[] widths = { 10, 16, 18, 20, 28 };

        if (rows.isEmpty()) {
            System.out.println("\n No past appointment history found. \n");
            return;
        }

        printTable(headers, rows, widths);
    }

    private static void updatePetDetails(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                        UPDATE PET DETAILS                           ");
        System.out.println("--------------------------------------------------------------------");

        try {
            String petId = readNonEmpty(sc, "\n Enter Pet ID : ");
            Pet pet = findPetById(petId);

            if (pet == null) {
                System.out.println("\n Pet ID not found. \n");
                return;
            }

            System.out.println("\n Current Pet Details :");
            System.out.println(" Pet ID           : " + pet.getPetId());
            System.out.println(" Name             : " + pet.getName());
            System.out.println(" Species/Breed    : " + pet.getSpeciesBreed());
            System.out.println(" Age              : " + pet.getAge());
            System.out.println(" Owner Name       : " + pet.getOwnerName());
            System.out.println(" Contact Info     : " + pet.getContactInfo());
            System.out.println(" Registration Date: " + formatDate(pet.getRegistrationDate()));
            System.out.println();

            String newName = readOptionalText(sc, " Enter New Name (press Enter to keep current) : ", pet.getName());
            String newSpeciesBreed = readOptionalText(sc, " Enter New Species/Breed (press Enter to keep current) : ", pet.getSpeciesBreed());
            int newAge = readOptionalPositiveInt(sc, " Enter New Age (press Enter to keep current) : ", pet.getAge());
            String newOwnerName = readOptionalText(sc, " Enter New Owner Name (press Enter to keep current) : ", pet.getOwnerName());
            String newContactInfo = readOptionalText(sc, " Enter New Contact Info (press Enter to keep current) : ", pet.getContactInfo());

            pet.setName(newName);
            pet.setSpeciesBreed(newSpeciesBreed);
            pet.setAge(newAge);
            pet.setOwnerName(newOwnerName);
            pet.setContactInfo(newContactInfo);

            System.out.println("\n Pet details updated successfully. \n");
        } catch (Exception e) {
            System.out.println("\n Error while updating pet details : " + e.getMessage() + "\n");
        }
    }

    private static void updateAppointmentByPetId(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                    UPDATE APPOINTMENTS BY PET ID                    ");
        System.out.println("--------------------------------------------------------------------");

        try {
            String petId = readNonEmpty(sc, "\n Enter Pet ID : ");
            Pet pet = findPetById(petId);

            if (pet == null) {
                System.out.println("\n Pet ID not found. \n");
                return;
            }

            if (pet.getAppointments().isEmpty()) {
                System.out.println("\n No appointments found for this pet. \n");
                return;
            }

            displayPetAppointmentsTable(pet);

            int index = readInt(sc, "\n Enter Appointment Number to Update : ");
            if (index < 1 || index > pet.getAppointments().size()) {
                System.out.println("\n Invalid appointment number. \n");
                return;
            }

            Appointment appointment = pet.getAppointments().get(index - 1);

            while (true) {
                System.out.println("\n--------------------------------------------------------------------");
                System.out.println("                     UPDATE APPOINTMENT DETAILS                      ");
                System.out.println("--------------------------------------------------------------------");
                System.out.println("   1) Update Appointment Type                                       ");
                System.out.println("   2) Update Date and Time                                          ");
                System.out.println("   3) Update Notes                                                  ");
                System.out.println("   4) Back                                                         ");
                System.out.println("--------------------------------------------------------------------");

                int choice = readInt(sc, "\n Enter your choice : ");

                switch (choice) {
                    case 1: {
                        String newType = readNonEmpty(sc, " Enter New Appointment Type : ");
                        appointment.setAppointmentType(newType);
                        pet.sortAppointments();
                        System.out.println("\n Appointment updated successfully. \n");
                        return;
                    }
                    case 2: {
                        String newDateText = readNonEmpty(sc, " Enter New Date and Time (dd-MM-yyyy HH:mm) : ");
                        LocalDateTime newDateTime = parseDateTimeFlexible(newDateText);
                        appointment.setDateTime(newDateTime);
                        pet.sortAppointments();
                        System.out.println("\n Appointment updated successfully. \n");
                        return;
                    }
                    case 3: {
                        System.out.print(" Enter New Notes (optional) : ");
                        String newNotes = sc.nextLine().trim();
                        appointment.setNotes(newNotes);
                        pet.sortAppointments();
                        System.out.println("\n Appointment updated successfully. \n");
                        return;
                    }
                    case 4:
                        return;
                    default:
                        System.out.println("\n Invalid Choice, Select again. \n");
                }
            }
        } catch (Exception e) {
            System.out.println("\n Error while updating appointment : " + e.getMessage() + "\n");
        }
    }

    private static void deletePet(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                            DELETE PET                               ");
        System.out.println("--------------------------------------------------------------------");

        try {
            String petId = readNonEmpty(sc, "\n Enter Pet ID to delete : ");
            Pet pet = findPetById(petId);

            if (pet == null) {
                System.out.println("\n Pet ID not found. \n");
                return;
            }

            System.out.println("\n Pet Details :");
            System.out.println(" Pet ID   : " + pet.getPetId());
            System.out.println(" Name     : " + pet.getName());
            System.out.println(" Owner    : " + pet.getOwnerName());
            System.out.println(" Appts    : " + pet.getAppointments().size());
            System.out.println();

            String confirm = readNonEmpty(sc, " Are you sure you want to delete this pet? (yes/no) : ");
            if (!isYes(confirm)) {
                System.out.println("\n Deletion cancelled. \n");
                return;
            }

            pets.remove(pet);
            petMap.remove(pet.getPetId());
            petIds.remove(pet.getPetId());

            System.out.println("\n Pet deleted successfully. \n");
        } catch (Exception e) {
            System.out.println("\n Error while deleting pet : " + e.getMessage() + "\n");
        }
    }

    private static void deleteAppointmentByPetId(Scanner sc) {
        System.out.println("\n--------------------------------------------------------------------");
        System.out.println("                 DELETE APPOINTMENT BY PET ID                        ");
        System.out.println("--------------------------------------------------------------------");

        try {
            String petId = readNonEmpty(sc, "\n Enter Pet ID : ");
            Pet pet = findPetById(petId);

            if (pet == null) {
                System.out.println("\n Pet ID not found. \n");
                return;
            }

            if (pet.getAppointments().isEmpty()) {
                System.out.println("\n No appointments found for this pet. \n");
                return;
            }

            displayPetAppointmentsTable(pet);

            int index = readInt(sc, "\n Enter Appointment Number to Delete : ");
            if (index < 1 || index > pet.getAppointments().size()) {
                System.out.println("\n Invalid appointment number. \n");
                return;
            }

            Appointment removed = pet.getAppointments().remove(index - 1);
            System.out.println("\n Appointment deleted successfully. ");
            System.out.println(" Deleted Type : " + removed.getAppointmentType() + "\n");
        } catch (Exception e) {
            System.out.println("\n Error while deleting appointment : " + e.getMessage() + "\n");
        }
    }

    private static void displayPetAppointmentsTable(Pet pet) {
        String[] headers = { "No", "Appointment Type", "Date and Time", "Notes" };
        int[] widths = { 4, 22, 20, 32 };

        List<String[]> rows = new ArrayList<>();
        int i = 1;
        for (Appointment a : pet.getAppointments()) {
            rows.add(new String[] {
                    String.valueOf(i++),
                    a.getAppointmentType(),
                    formatDateTime(a.getDateTime()),
                    a.getNotes() == null || a.getNotes().isBlank() ? "N/A" : a.getNotes()
            });
        }

        System.out.println("\n Pet ID     : " + pet.getPetId());
        System.out.println(" Pet Name   : " + pet.getName());
        System.out.println(" Owner Name : " + pet.getOwnerName());
        System.out.println();
        printTable(headers, rows, widths);
    }

    private static void printTable(String[] headers, List<String[]> rows, int[] widths) {
        String border = buildBorder(widths);

        System.out.println(border);
        System.out.println(formatRow(headers, widths));
        System.out.println(border);

        for (String[] row : rows) {
            System.out.println(formatRow(row, widths));
        }

        System.out.println(border);
    }

    private static String buildBorder(int[] widths) {
        StringBuilder sb = new StringBuilder();
        sb.append('+');
        for (int w : widths) {
            sb.append(repeat('-', w + 2)).append('+');
        }
        return sb.toString();
    }

    private static String formatRow(String[] cells, int[] widths) {
        StringBuilder sb = new StringBuilder();
        sb.append('|');

        for (int i = 0; i < widths.length; i++) {
            String cell = i < cells.length ? cells[i] : "";
            cell = cell == null ? "" : cell;
            sb.append(' ')
              .append(padRight(truncate(cell, widths[i]), widths[i]))
              .append(' ')
              .append('|');
        }

        return sb.toString();
    }

    private static String padRight(String text, int width) {
        if (text.length() >= width) return text;
        return text + repeat(' ', width - text.length());
    }

    private static String truncate(String text, int width) {
        if (text.length() <= width) return text;
        if (width <= 3) return text.substring(0, width);
        return text.substring(0, width - 3) + "...";
    }

    private static String repeat(char ch, int count) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < count; i++) sb.append(ch);
        return sb.toString();
    }

    private static String readNonEmpty(Scanner sc, String prompt) {
        String value;
        do {
            System.out.print(prompt);
            value = sc.nextLine().trim();
        } while (value.isEmpty());
        return value;
    }

    private static String readOptionalText(Scanner sc, String prompt, String currentValue) {
        System.out.print(prompt);
        String value = sc.nextLine().trim();
        return value.isEmpty() ? currentValue : value;
    }

    private static int readInt(Scanner sc, String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                return Integer.parseInt(sc.nextLine().trim());
            } catch (NumberFormatException e) {
                System.out.println("\n Please enter a valid number. \n");
            }
        }
    }

    private static int readPositiveInt(Scanner sc, String prompt) {
        while (true) {
            int value = readInt(sc, prompt);
            if (value > 0) return value;
            System.out.println("\n Value must be greater than 0. \n");
        }
    }

    private static int readOptionalPositiveInt(Scanner sc, String prompt, int currentValue) {
        while (true) {
            System.out.print(prompt);
            String value = sc.nextLine().trim();

            if (value.isEmpty()) {
                return currentValue;
            }

            try {
                int parsed = Integer.parseInt(value);
                if (parsed > 0) {
                    return parsed;
                }
                System.out.println("\n Value must be greater than 0. \n");
            } catch (NumberFormatException e) {
                System.out.println("\n Please enter a valid number or press Enter to keep current value. \n");
            }
        }
    }

    private static boolean petIdExists(String petId) {
        for (String id : petIds) {
            if (id.equalsIgnoreCase(petId)) {
                return true;
            }
        }
        return false;
    }

    private static Pet findPetById(String petId) {
        Pet pet = petMap.get(petId);
        if (pet != null) {
            return pet;
        }

        for (Pet p : pets) {
            if (p.getPetId().equalsIgnoreCase(petId)) {
                return p;
            }
        }
        return null;
    }

    private static String formatDate(LocalDate date) {
        return date == null ? "N/A" : date.format(DATE_FORMATTER);
    }

    private static String formatDateTime(LocalDateTime dateTime) {
        return dateTime == null ? "N/A" : dateTime.format(DISPLAY_DATE_TIME_FORMATTER);
    }

    private static LocalDateTime parseDateTimeFlexible(String text) {
        DateTimeFormatter[] formatters = new DateTimeFormatter[] {
                INPUT_DASH_FORMATTER,
                INPUT_SLASH_FORMATTER,
                INPUT_COLON_FORMATTER
        };

        for (DateTimeFormatter formatter : formatters) {
            try {
                return LocalDateTime.parse(text, formatter);
            } catch (DateTimeParseException ignored) {
            }
        }

        throw new DateTimeParseException("Invalid date and time format", text, 0);
    }

    private static void saveData() {
        try (ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(DATA_FILE))) {
            out.writeObject(pets);
        } catch (IOException e) {
            System.out.println("\n Warning: could not save data -> " + e.getMessage());
        }
    }

    @SuppressWarnings("unchecked")
    private static void loadData() {
        File file = new File(DATA_FILE);
        if (!file.exists()) {
            pets = new ArrayList<>();
            return;
        }

        try (ObjectInputStream in = new ObjectInputStream(new FileInputStream(file))) {
            Object obj = in.readObject();
            if (obj instanceof List<?>) {
                pets = (List<Pet>) obj;
            } else {
                pets = new ArrayList<>();
            }
        } catch (IOException | ClassNotFoundException e) {
            pets = new ArrayList<>();
            System.out.println("\n Warning: could not load previous data -> " + e.getMessage());
        }
    }

    private static void rebuildIndex() {
        petMap.clear();
        petIds.clear();

        for (Pet pet : pets) {
            petMap.put(pet.getPetId(), pet);
            petIds.add(pet.getPetId());
        }
    }

    private static void exitProgram(Scanner sc) {
        System.out.print("\n Exit without saving? Type yes to exit, or save before leaving with option 6 : ");
        String choice = sc.nextLine().trim();

        if (isYes(choice)) {
            System.out.println("\n Exiting... \n");
        } else {
            System.out.println("\n Exit cancelled. \n");
        }
    }

    private static boolean isYes(String text) {
        if (text == null) return false;
        String t = text.trim().toLowerCase();
        return t.equals("yes") || t.equals("y");
    }

    static class Pet implements Serializable {
        private static final long serialVersionUID = 1L;

        private final String petId;
        private String name;
        private String speciesBreed;
        private int age;
        private String ownerName;
        private String contactInfo;
        private LocalDate registrationDate;
        private final List<Appointment> appointments = new ArrayList<>();

        public Pet(String petId, String name, String speciesBreed, int age,
                   String ownerName, String contactInfo, LocalDate registrationDate) {
            this.petId = petId;
            this.name = name;
            this.speciesBreed = speciesBreed;
            this.age = age;
            this.ownerName = ownerName;
            this.contactInfo = contactInfo;
            this.registrationDate = registrationDate;
        }

        public String getPetId() {
            return petId;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public String getSpeciesBreed() {
            return speciesBreed;
        }

        public void setSpeciesBreed(String speciesBreed) {
            this.speciesBreed = speciesBreed;
        }

        public int getAge() {
            return age;
        }

        public void setAge(int age) {
            this.age = age;
        }

        public String getOwnerName() {
            return ownerName;
        }

        public void setOwnerName(String ownerName) {
            this.ownerName = ownerName;
        }

        public String getContactInfo() {
            return contactInfo;
        }

        public void setContactInfo(String contactInfo) {
            this.contactInfo = contactInfo;
        }

        public LocalDate getRegistrationDate() {
            return registrationDate;
        }

        public List<Appointment> getAppointments() {
            return appointments;
        }

        public void addAppointment(Appointment appointment) {
            if (appointment != null) {
                appointments.add(appointment);
                sortAppointments();
            }
        }

        public void sortAppointments() {
            appointments.sort((a, b) -> a.getDateTime().compareTo(b.getDateTime()));
        }
    }

    static class Appointment implements Serializable {
        private static final long serialVersionUID = 1L;

        private String appointmentType;
        private LocalDateTime dateTime;
        private String notes;

        public Appointment(String appointmentType, LocalDateTime dateTime, String notes) {
            this.appointmentType = appointmentType;
            this.dateTime = dateTime;
            this.notes = notes;
        }

        public String getAppointmentType() {
            return appointmentType;
        }

        public void setAppointmentType(String appointmentType) {
            this.appointmentType = appointmentType;
        }

        public LocalDateTime getDateTime() {
            return dateTime;
        }

        public void setDateTime(LocalDateTime dateTime) {
            this.dateTime = dateTime;
        }

        public String getNotes() {
            return notes;
        }

        public void setNotes(String notes) {
            this.notes = notes;
        }
    }
}