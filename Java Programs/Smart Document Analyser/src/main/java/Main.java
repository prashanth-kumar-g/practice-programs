// ===================== SMART DOCUMENT ANALYZER =====================
// Desktop application for document analysis and text intelligence
// Key Features:
//   - Supports TXT, PDF, DOCX, XLSX, PPTX document formats
//   - Extracts 12 deep text intelligence metrics
//   - Displays PDF page thumbnail after file upload
//   - Drag & Drop file upload support
//   - Fixed proportional 42/58 card split layout
//   - Live status bar with color-coded feedback
// ===================================================================

import com.formdev.flatlaf.FlatLightLaf;
import org.apache.pdfbox.Loader;
import org.apache.pdfbox.rendering.PDFRenderer;
import org.apache.pdfbox.text.PDFTextStripper;
import org.apache.poi.extractor.ExtractorFactory;
import org.apache.poi.extractor.POITextExtractor;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.CompoundBorder;
import javax.swing.border.EmptyBorder;
import javax.swing.border.LineBorder;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.awt.*;
import java.awt.datatransfer.DataFlavor;
import java.awt.image.BufferedImage;
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


// ===================== Main Class =====================

public class Main extends JFrame {


    // ═════════════════════════════════════════════════════════════════════════
    //  COLOR CONSTANTS
    // ═════════════════════════════════════════════════════════════════════════

    // --- APP BACKGROUND COLORS ---
    // Soft slate gradient used as the window's base background
    private static final Color APP_BG_TOP    = new Color(248, 250, 252);   // Slate-50  — top of gradient
    private static final Color APP_BG_BOTTOM = new Color(241, 245, 249);   // Slate-100 — bottom of gradient

    // --- HEADER COLORS ---
    // Deep navy gradient with indigo glow for the top navigation bar
    private static final Color HEADER_START  = new Color(15, 23, 42);      // Slate-900 — left of header gradient
    private static final Color HEADER_MID    = new Color(30, 41, 59);      // Slate-800 — right of header gradient
    private static final Color HEADER_GLOW   = new Color(99, 102, 241);    // Indigo-500 — right-side glow accent
    private static final Color HEADER_BTN    = new Color(55, 65, 81);      // Gray-700  — Browse File button base color

    // --- CARD COLORS ---
    // White cards with a subtle slate inner fill for metric tiles and pills
    private static final Color CARD_BG       = Color.WHITE;                // Pure white — outer card fill
    private static final Color CARD_BORDER   = new Color(226, 232, 240);   // Slate-200 — card outline stroke
    private static final Color INNER_BG      = new Color(248, 250, 252);   // Slate-50  — tile and pill background

    // --- TEXT COLORS ---
    // High-contrast slate text for readability on white backgrounds
    private static final Color TEXT_PRIMARY   = new Color(15, 23, 42);     // Slate-900 — headings and values
    private static final Color TEXT_SECONDARY = new Color(71, 85, 105);    // Slate-600 — labels and descriptions

    // --- ACCENT PALETTE ---
    // Individual colors assigned to each metric tile, button, and status state
    private static final Color PRIMARY = new Color(79, 70, 229);    // Indigo   — Analyze button and Unique Words tile
    private static final Color INFO    = new Color(14, 165, 233);   // Sky-blue — Character Count tile
    private static final Color SUCCESS = new Color(16, 185, 129);   // Emerald  — Word Count tile and file upload confirm
    private static final Color GREEN   = new Color(22, 163, 74);    // Green    — Clear button
    private static final Color WARNING = new Color(245, 158, 11);   // Amber    — Paragraph Count tile and uploading state
    private static final Color DANGER  = new Color(239, 68, 68);    // Red      — Exit button and Most Repeated Word tile
    private static final Color PURPLE  = new Color(168, 85, 247);   // Violet   — Sentence Count tile
    private static final Color TEAL    = new Color(20, 184, 166);   // Teal     — Smallest Word tile
    private static final Color PINK    = new Color(236, 72, 153);   // Pink     — Longest Word tile
    private static final Color ORANGE  = new Color(249, 115, 22);   // Orange   — Avg Word Length tile
    private static final Color INDIGO  = new Color(99, 102, 241);   // Indigo   — Avg Sentence Length tile and analysing state
    private static final Color CYAN    = new Color(14, 116, 144);   // Cyan     — Avg Paragraph Length tile
    private static final Color LIME    = new Color(101, 163, 13);   // Lime     — Total Pages tile


    // ═════════════════════════════════════════════════════════════════════════
    //  FONT CONSTANTS
    // ═════════════════════════════════════════════════════════════════════════

    // --- FONT DEFINITIONS ---
    // Shared Segoe UI font instances used consistently across all UI components
    private static final Font FONT_TITLE    = new Font("Segoe UI", Font.BOLD,  30);  // Header main title
    private static final Font FONT_SUBTITLE = new Font("Segoe UI", Font.PLAIN, 14);  // Header subtitle description
    private static final Font FONT_SECTION  = new Font("Segoe UI", Font.BOLD,  17);  // Card section headings
    private static final Font FONT_DESC     = new Font("Segoe UI", Font.PLAIN, 14);  // Card subtitle descriptions
    private static final Font FONT_LABEL    = new Font("Segoe UI", Font.BOLD,  13);  // Tile and pill label text
    private static final Font FONT_VALUE    = new Font("Segoe UI", Font.BOLD,  13);  // Pill value text (file name, type, size)
    private static final Font FONT_STATUS   = new Font("Segoe UI", Font.BOLD,  13);  // Status bar message text


    // ═════════════════════════════════════════════════════════════════════════
    //  STATE VARIABLES
    // ═════════════════════════════════════════════════════════════════════════

    // --- APPLICATION STATE ---
    private File           selectedFile;   // Currently selected document file (null if none)
    private AnalysisResult lastResult;     // Most recent analysis result (null until analyzed)


    // ═════════════════════════════════════════════════════════════════════════
    //  UI COMPONENT DECLARATIONS
    // ═════════════════════════════════════════════════════════════════════════

    // --- FILE INFO LABELS ---
    // Dynamic labels populated when a file is selected or analyzed
    private final JLabel fileNameValue = new JLabel("-");   // Displays selected file's name
    private final JLabel fileTypeValue = new JLabel("-");   // Displays selected file's extension
    private final JLabel fileSizeValue = new JLabel("-");   // Displays selected file's size in B/KB/MB

    // --- STATUS LABEL ---
    // Live status indicator shown next to Browse File button
    private final JLabel statusLabel = new JLabel();    // Shows current action state with colored dot prefix

    // --- 12 METRIC LABELS ---
    // All labels are initialized to "-" and populated after analysis completes
    private final JLabel charCountValue          = new JLabel("-");  // Total character count
    private final JLabel wordCountValue          = new JLabel("-");  // Total word count
    private final JLabel sentenceCountValue      = new JLabel("-");  // Total sentence count
    private final JLabel paragraphCountValue     = new JLabel("-");  // Total paragraph count
    private final JLabel smallestWordValue       = new JLabel("-");  // Shortest word found
    private final JLabel longestWordValue        = new JLabel("-");  // Longest word found
    private final JLabel uniqueWordsValue        = new JLabel("-");  // Count of distinct vocabulary words
    private final JLabel frequentWordValue       = new JLabel("-");  // Most repeated word and its count
    private final JLabel avgWordLengthValue      = new JLabel("-");  // Average word length in characters
    private final JLabel avgSentenceLengthValue  = new JLabel("-");  // Average sentence length in words and lines
    private final JLabel avgParagraphLengthValue = new JLabel("-");  // Average paragraph length in sentences and lines
    private final JLabel totalPagesValue         = new JLabel("-");  // Page count (PDF only, else N/A)

    // --- ACTION BUTTONS ---
    // All four buttons use StyledButton for consistent gradient painting
    private final StyledButton browseButton  = new StyledButton("Browse File", HEADER_BTN);  // Opens file chooser dialog
    private final StyledButton analyzeButton = new StyledButton("Analyze",     PRIMARY);      // Triggers document analysis
    private final StyledButton clearButton   = new StyledButton("Clear",       GREEN);         // Resets all data and UI
    private final StyledButton exitButton    = new StyledButton("Exit",        DANGER);        // Exits application after 2s delay

    // --- DROP AREA PANEL ---
    // Declared as a field so setSelectedFile() and clearAll() can switch its view states
    private final DropAreaPanel dropArea = new DropAreaPanel();   // Handles PROMPT / LOADING / THUMB views


    // ═════════════════════════════════════════════════════════════════════════
    //  CONSTRUCTOR
    // ═════════════════════════════════════════════════════════════════════════

    // --- CONSTRUCTOR ---
    // Initializes the application window, builds all UI panels, wires button actions
    // Note: Status label sizing is applied here to prevent layout collapse before first setStatus() call

    public Main() {

        super("Smart Document Analyzer");   // Set JFrame window title

        // -------- Application Initialization --------
        configureLookAndFeel();    // Apply FlatLaf theme and UI manager overrides
        configureWindow();         // Set window size, minimum bounds, and center position
        setContentPane(buildRoot());   // Assemble and attach the root panel hierarchy
        wireActions();             // Register all button action listeners

        // -------- Initial Status Setup --------
        setStatus("No file uploaded", TEXT_SECONDARY);   // Default startup status message

        // Fix status label size so it is visible without breaking the card layout
        statusLabel.setMinimumSize(new Dimension(100, 40));              // Prevent shrinking to zero
        statusLabel.setPreferredSize(new Dimension(200, 40));            // Reasonable default width
        statusLabel.setMaximumSize(new Dimension(Integer.MAX_VALUE, 40)); // Allow horizontal stretch but lock height
        statusLabel.setFont(FONT_STATUS);   // Apply bold status font

    }

    // --- MAIN ENTRY POINT ---
    // Launches the application on the Swing Event Dispatch Thread

    public static void main(String[] args) {

        SwingUtilities.invokeLater(() -> {
            try { FlatLightLaf.setup(); } catch (Exception ignored) {}  // Apply FlatLaf modern look-and-feel
            new Main().setVisible(true);   // Instantiate and display main window
        });

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  SETUP
    // ═════════════════════════════════════════════════════════════════════════

    // --- LOOK AND FEEL CONFIGURATION ---
    // Applies FlatLaf component rounding and overrides default Swing table/scrollbar behavior

    private void configureLookAndFeel() {

        UIManager.put("TitlePane.centerTitle", true);              // Center the window title in the title bar
        UIManager.put("Component.arc", 18);                        // Global component corner rounding
        UIManager.put("Button.arc", 18);                           // Button corner rounding
        UIManager.put("TextComponent.arc", 14);                    // Text field corner rounding
        UIManager.put("ScrollBar.thumbArc", 999);                  // Fully round scrollbar thumb
        UIManager.put("TabbedPane.arc", 18);                       // Tab pane corner rounding
        UIManager.put("ProgressBar.arc", 999);                     // Fully round progress bar
        UIManager.put("Component.focusWidth", 1);                  // Slim focus ring
        UIManager.put("Table.showHorizontalLines", true);          // Show horizontal grid lines in tables
        UIManager.put("Table.showVerticalLines", false);           // Hide vertical grid lines in tables
        UIManager.put("Table.intercellSpacing", new Dimension(0, 8));  // Row spacing

    }

    // --- WINDOW CONFIGURATION ---
    // Sets window dimensions, minimum size constraint, and centers on screen

    private void configureWindow() {

        setDefaultCloseOperation(EXIT_ON_CLOSE);           // Terminate JVM on window close
        setMinimumSize(new Dimension(1280, 820));          // Prevent window from being resized too small
        setSize(1320, 860);                                // Default launch size
        setLocationRelativeTo(null);                       // Center on screen

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  UI BUILD
    // ═════════════════════════════════════════════════════════════════════════

    // --- ROOT PANEL BUILDER ---
    // Assembles the top-level panel with header and center content areas

    private JPanel buildRoot() {

        JPanel root = new GradientBackgroundPanel(new BorderLayout(16, 16));  // Gradient bg with spacing between header and center
        root.setBorder(new EmptyBorder(14, 14, 14, 14));  // Outer padding around entire window content
        root.add(buildHeader(), BorderLayout.NORTH);       // Navigation bar at top
        root.add(buildCenter(), BorderLayout.CENTER);      // Main content area below
        return root;

    }

    // --- HEADER PANEL BUILDER ---
    // Builds the dark navy navigation bar with title, subtitle, format chips, and stats grid

    private JPanel buildHeader() {

        GradientHeaderPanel header = new GradientHeaderPanel(new BorderLayout(18, 18));
        header.setBorder(new EmptyBorder(22, 24, 22, 24));   // Internal padding for header content

        // -------- Left Side: Title, Subtitle, Format Chips --------
        JPanel left = new JPanel();
        left.setOpaque(false);
        left.setLayout(new BoxLayout(left, BoxLayout.Y_AXIS));   // Stack items vertically

        JLabel title = new JLabel("Smart Document Analyzer");
        title.setForeground(Color.WHITE);                  // White text on dark header
        title.setFont(FONT_TITLE);
        title.setAlignmentX(Component.LEFT_ALIGNMENT);     // Align to left edge

        JLabel subtitle = new JLabel(
                "Upload any document and unlock 12 deep text intelligence metrics"
                + " covering vocabulary, structure and readability.");
        subtitle.setForeground(new Color(203, 213, 225));  // Slate-300 — softer white for subtitle
        subtitle.setFont(FONT_SUBTITLE);
        subtitle.setAlignmentX(Component.LEFT_ALIGNMENT);

        // Supported format chips row
        JPanel chips = new JPanel(new FlowLayout(FlowLayout.LEFT, 8, 0));
        chips.setOpaque(false);
        chips.setAlignmentX(Component.LEFT_ALIGNMENT);
        chips.add(chip("TXT",  new Color(255, 255, 255, 35), Color.WHITE));   // Plain text chip
        chips.add(chip("PDF",  new Color(255, 255, 255, 35), Color.WHITE));   // PDF chip
        chips.add(chip("DOCX", new Color(255, 255, 255, 35), Color.WHITE));   // Word document chip
        chips.add(chip("XLSX", new Color(255, 255, 255, 35), Color.WHITE));   // Excel spreadsheet chip
        chips.add(chip("PPTX", new Color(255, 255, 255, 35), Color.WHITE));   // PowerPoint presentation chip

        left.add(title);
        left.add(Box.createVerticalStrut(6));    // Space between title and subtitle
        left.add(subtitle);
        left.add(Box.createVerticalStrut(14));   // Space between subtitle and chips
        left.add(chips);

        // -------- Right Side: 2x2 Hero Stats Grid --------
        JPanel stats = new JPanel(new GridLayout(2, 2, 10, 10));   // 2 rows × 2 columns
        stats.setOpaque(false);
        stats.add(heroStat("Fast Analysis", "One click",      SUCCESS));   // Highlight: one-click analysis
        stats.add(heroStat("Modern UI",     "Colorful layout", INFO));     // Highlight: modern interface
        stats.add(heroStat("12 Metrics",    "Deep insights",   PURPLE));   // Highlight: metric count
        stats.add(heroStat("Drag & Drop",   "Quick upload",    TEAL));     // Highlight: drag-and-drop support

        header.add(left,  BorderLayout.WEST);   // Title content on left
        header.add(stats, BorderLayout.EAST);   // Stats grid on right
        return header;

    }

    // --- CENTER LAYOUT BUILDER ---
    // Arranges the left stack (upload + buttons) and right analysis card using ProportionalLayout
    // Note: ProportionalLayout is used here instead of GridBagLayout because it sets bounds
    //       directly from actual pixel width — content can never push the card wider

    private JPanel buildCenter() {

        // ProportionalLayout enforces a strict 42/58 split regardless of child content size
        JPanel center = new JPanel(new ProportionalLayout(0.42f, 16)) {
            @Override public Dimension getPreferredSize() {
                return new Dimension(0, 0);   // Prevent this panel itself from inflating the parent
            }
        };
        center.setOpaque(false);

        // -------- Left Column: Upload Card + Buttons Card --------
        JPanel leftStack = new JPanel(new BorderLayout(0, 12));   // 12px vertical gap between cards
        leftStack.setOpaque(false);
        leftStack.add(buildUploadCard(),  BorderLayout.CENTER);   // Upload card fills available height
        leftStack.add(buildButtonsCard(), BorderLayout.SOUTH);    // Buttons card is pinned to bottom

        center.add(leftStack);             // First child = left (42%)
        center.add(buildAnalysisCard());   // Second child = right (58%)
        return center;

    }

    // --- UPLOAD CARD BUILDER ---
    // Builds the left card containing: section heading, drop area, browse/status row, file info pills

    private JPanel buildUploadCard() {

        CardPanel card = new CardPanel();
        card.setLayout(new BorderLayout(0, 14));   // 14px vertical gap between top header and body
        card.setBorder(new CompoundBorder(
                new LineBorder(CARD_BORDER, 1, true),     // Outer slate border
                new EmptyBorder(18, 18, 18, 18)));         // Inner padding

        // -------- Section Heading --------
        JPanel top = new JPanel();
        top.setOpaque(false);
        top.setLayout(new BorderLayout(0, 4));   // 4px gap between heading and description

        JLabel heading = new JLabel("Document Input");
        heading.setFont(FONT_SECTION);
        heading.setForeground(TEXT_PRIMARY);

        JLabel desc = new JLabel("Choose a document or drag and drop it here.");
        desc.setForeground(TEXT_SECONDARY);
        desc.setFont(FONT_DESC);

        top.add(heading, BorderLayout.NORTH);   // Bold section title
        top.add(desc,    BorderLayout.SOUTH);   // Descriptive subtitle

        // -------- Drop Zone --------
        // Fixed height prevents the card from growing when content changes
        dropArea.setTransferHandler(new FileDropHandler());            // Enable drag-and-drop file reception
        dropArea.setMaximumSize(new Dimension(Integer.MAX_VALUE, 270));   // Lock maximum height
        dropArea.setMinimumSize(new Dimension(10, 270));               // Lock minimum height
        dropArea.setPreferredSize(new Dimension(10, 270));             // Tiny preferred width so layout ignores it
        dropArea.setAlignmentX(Component.LEFT_ALIGNMENT);

        // -------- Browse Button + Status Row --------
        // Uses BoxLayout X_AXIS so the button is never vertically stretched
        browseButton.setAlignmentY(Component.CENTER_ALIGNMENT);   // Vertically center button within row
        statusLabel.setAlignmentY(Component.CENTER_ALIGNMENT);    // Vertically center status label within row

        JPanel browseRow = new JPanel();
        browseRow.setOpaque(false);
        browseRow.setLayout(new BoxLayout(browseRow, BoxLayout.X_AXIS));  // Horizontal layout
        browseRow.setMaximumSize(new Dimension(Integer.MAX_VALUE, 44));   // Lock row height
        browseRow.setMinimumSize(new Dimension(10, 44));
        browseRow.setPreferredSize(new Dimension(10, 44));
        browseRow.setAlignmentX(Component.LEFT_ALIGNMENT);
        browseRow.add(browseButton);                     // Browse File button on the left
        browseRow.add(Box.createHorizontalStrut(14));    // Fixed gap between button and status label
        browseRow.add(statusLabel);                      // Status message fills remaining space
        browseRow.add(Box.createHorizontalGlue());       // Push everything left

        // -------- File Info Pills Row (2:1:1 width ratio) --------
        // GridBagLayout with weightx values gives File Name twice the space of File Type and File Size
        JPanel fileInfoRow = new JPanel(new GridBagLayout());
        fileInfoRow.setOpaque(false);
        fileInfoRow.setMaximumSize(new Dimension(Integer.MAX_VALUE, 72));   // Lock row height
        fileInfoRow.setMinimumSize(new Dimension(10, 72));
        fileInfoRow.setPreferredSize(new Dimension(10, 72));
        fileInfoRow.setAlignmentX(Component.LEFT_ALIGNMENT);

        GridBagConstraints fc = new GridBagConstraints();
        fc.gridy = 0; fc.weighty = 1.0; fc.fill = GridBagConstraints.BOTH;

        fc.gridx = 0; fc.weightx = 2.0; fc.insets = new Insets(0, 0, 0, 10);
        fileInfoRow.add(infoPill("File Name", fileNameValue, INFO), fc);    // Wide pill for file name

        fc.gridx = 1; fc.weightx = 1.0;
        fileInfoRow.add(infoPill("File Type", fileTypeValue, PURPLE), fc);  // Half-width pill for file type

        fc.gridx = 2; fc.weightx = 1.0; fc.insets = new Insets(0, 0, 0, 0);
        fileInfoRow.add(infoPill("File Size", fileSizeValue, SUCCESS), fc); // Half-width pill for file size

        // -------- Card Body Assembly --------
        JPanel body = new JPanel();
        body.setOpaque(false);
        body.setLayout(new BoxLayout(body, BoxLayout.Y_AXIS));   // Stack all rows vertically
        body.add(dropArea);
        body.add(Box.createVerticalStrut(12));   // Gap between drop area and browse row
        body.add(browseRow);
        body.add(Box.createVerticalStrut(12));   // Gap between browse row and file info pills
        body.add(fileInfoRow);

        card.add(top,  BorderLayout.NORTH);     // Section heading pinned to top
        card.add(body, BorderLayout.CENTER);    // Body fills remaining card space
        return card;

    }

    // --- BUTTONS CARD BUILDER ---
    // Builds the bottom-left card containing Analyze, Clear, and Exit buttons side by side

    private JPanel buildButtonsCard() {

        CardPanel card = new CardPanel();
        card.setLayout(new BorderLayout());
        card.setBorder(new CompoundBorder(
                new LineBorder(CARD_BORDER, 1, true),     // Outer slate border
                new EmptyBorder(16, 18, 16, 18)));         // Inner padding

        // Equal-width 3-column grid for three buttons
        JPanel buttons = new JPanel(new GridLayout(1, 3, 12, 0));  // 12px horizontal gap between buttons
        buttons.setOpaque(false);
        buttons.add(analyzeButton);   // Primary action — triggers document analysis
        buttons.add(clearButton);     // Secondary action — resets all data and UI
        buttons.add(exitButton);      // Destructive action — exits the application

        card.add(buttons, BorderLayout.CENTER);
        return card;

    }

    // --- ANALYSIS CARD BUILDER ---
    // Builds the right card containing Document Intelligence heading and 12 metric tiles in a 6×2 grid

    private JPanel buildAnalysisCard() {

        CardPanel card = new CardPanel();
        card.setLayout(new BorderLayout(0, 14));   // 14px gap between heading and tile grid
        card.setBorder(new CompoundBorder(
                new LineBorder(CARD_BORDER, 1, true),     // Outer slate border
                new EmptyBorder(18, 18, 18, 18)));         // Inner padding

        // -------- Section Heading --------
        JPanel top = new JPanel(new BorderLayout(0, 4));   // 4px gap between heading and description
        top.setOpaque(false);

        JLabel heading = new JLabel("Document Intelligence");
        heading.setFont(FONT_SECTION);
        heading.setForeground(TEXT_PRIMARY);

        JLabel desc = new JLabel("Analyze a document to populate all metrics below.");
        desc.setForeground(TEXT_SECONDARY);
        desc.setFont(FONT_DESC);

        top.add(heading, BorderLayout.NORTH);   // Bold section title
        top.add(desc,    BorderLayout.SOUTH);   // Descriptive subtitle

        // -------- 12 Metric Tiles (6 rows × 2 columns) --------
        JPanel tiles = new JPanel(new GridLayout(6, 2, 12, 12));   // 12px gap between all tiles
        tiles.setOpaque(false);

        // Row 1 — Basic count metrics
        tiles.add(metricTile  ("Character Count",      charCountValue,          INFO));     // Total chars including spaces
        tiles.add(metricTile  ("Word Count",            wordCountValue,          SUCCESS));  // Total word tokens

        // Row 2 — Structural count metrics
        tiles.add(metricTile  ("Sentence Count",        sentenceCountValue,      PURPLE));   // Sentences split by .!?
        tiles.add(metricTile  ("Paragraph Count",       paragraphCountValue,     WARNING));  // Paragraphs split by blank lines

        // Row 3 — Word length extremes
        tiles.add(metricTile  ("Smallest Word",         smallestWordValue,       TEAL));     // Shortest word in document
        tiles.add(metricTile  ("Longest Word",          longestWordValue,        PINK));     // Longest word in document

        // Row 4 — Vocabulary metrics
        tiles.add(metricTile  ("Unique Words",          uniqueWordsValue,        PRIMARY));  // Count of distinct word types
        tiles.add(metricTile  ("Most Repeated Word",    frequentWordValue,       DANGER));   // Word with highest frequency

        // Row 5 — Average length metrics (smaller font — values can be longer strings)
        tiles.add(metricTileSm("Avg Word Length",       avgWordLengthValue,      ORANGE));   // Mean word length in characters
        tiles.add(metricTileSm("Avg Sentence Length",   avgSentenceLengthValue,  INDIGO));   // Mean sentence length in words and lines

        // Row 6 — Structural averages and page count
        tiles.add(metricTileSm("Avg Paragraph Length",  avgParagraphLengthValue, CYAN));    // Mean paragraph length in sentences and lines
        tiles.add(metricTile  ("Total Pages",           totalPagesValue,         LIME));     // Page count (PDF only, N/A for others)

        card.add(top,   BorderLayout.NORTH);    // Section heading pinned to top
        card.add(tiles, BorderLayout.CENTER);   // Tile grid fills remaining card space
        return card;

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  ACTIONS
    // ═════════════════════════════════════════════════════════════════════════

    // --- ACTION WIRING ---
    // Registers all button click listeners with their corresponding handler methods

    private void wireActions() {

        browseButton.addActionListener(e -> chooseFile());             // Open file chooser dialog
        analyzeButton.addActionListener(e -> analyzeSelectedFile());   // Start background analysis
        clearButton.addActionListener(e -> clearAll());                // Reset all state and UI
        exitButton.addActionListener(e -> triggerExit());              // Show exit status then close

    }

    // --- FILE CHOOSER ---
    // Opens a JFileChooser dialog filtered to supported document formats
    // Note: Only triggers setSelectedFile() if user confirms a selection

    private void chooseFile() {

        JFileChooser chooser = new JFileChooser();
        chooser.setDialogTitle("Select a document");
        chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);       // Disallow folder selection
        chooser.setAcceptAllFileFilterUsed(true);                     // Keep "All Files" option
        chooser.addChoosableFileFilter(new FileNameExtensionFilter(
                "Supported Documents (*.txt, *.pdf, *.docx, *.xlsx, *.pptx)",
                "txt", "pdf", "docx", "xlsx", "pptx"));              // Suggest only supported formats

        if (chooser.showOpenDialog(this) == JFileChooser.APPROVE_OPTION)
            setSelectedFile(chooser.getSelectedFile());   // Proceed only if user confirmed selection

    }

    // --- FILE SELECTION HANDLER ---
    // Updates all file info fields, triggers thumbnail loading, and sets status
    // Note: Status shows "Uploading..." briefly then "File uploaded" after 400ms

    private void setSelectedFile(File file) {

        selectedFile = file;
        setStatus("Uploading file...", WARNING);   // Immediate feedback on selection

        // -------- File Info Pill Updates --------
        String name = file.getName();
        fileNameValue.setText(name);                                        // Display full file name
        fileTypeValue.setText(getExtension(file).toUpperCase(Locale.ROOT)); // Display extension in uppercase
        fileSizeValue.setText(formatBytes(file.length()));                  // Display formatted file size
        lastResult = null;   // Invalidate previous analysis result

        // -------- Thumbnail Loading --------
        dropArea.showLoading();   // Switch drop area to loading view immediately
        loadThumbnail(file, getExtension(file).toLowerCase(Locale.ROOT));   // Start async thumbnail render

        // -------- Delayed Success Status --------
        // Short delay simulates upload feedback before confirming
        Timer t = new Timer(400, e -> setStatus("File uploaded successfully \u2713", GREEN));
        t.setRepeats(false);
        t.start();

    }

    // --- THUMBNAIL LOADER ---
    // Renders the first page of a PDF at 72 DPI in a background SwingWorker
    // Note: Returns null for non-PDF files; DropAreaPanel shows file type icon instead

    private void loadThumbnail(File file, String ext) {

        SwingWorker<BufferedImage, Void> worker = new SwingWorker<>() {

            // -------- Background Task: PDF Rendering --------
            @Override protected BufferedImage doInBackground() {
                if ("pdf".equals(ext)) {
                    try (var doc = Loader.loadPDF(file)) {
                        PDFRenderer renderer = new PDFRenderer(doc);
                        return renderer.renderImageWithDPI(0, 72);   // Render page 0 at 72 DPI
                    } catch (Exception ignored) {}
                }
                return null;   // Non-PDF returns null — triggers file icon mode in DropAreaPanel
            }

            // -------- EDT Callback: Pass Thumbnail to Drop Area --------
            @Override protected void done() {
                try {
                    BufferedImage img = get();
                    dropArea.showThumbnail(img, file.getName(),
                            getExtension(file).toUpperCase(Locale.ROOT));   // Pass image (or null) and file metadata
                } catch (Exception ignored) {
                    dropArea.showPrompt();   // Fall back to original prompt on any error
                }
            }

        };
        worker.execute();   // Start background thread

    }

    // --- DOCUMENT ANALYSIS ---
    // Validates file selection, then runs text extraction and metric computation in a SwingWorker
    // Note: All heavy work runs off the EDT to keep UI responsive during analysis

    private void analyzeSelectedFile() {

        if (selectedFile == null) {
            JOptionPane.showMessageDialog(this,
                    "Please select a file first.", "No File Selected",
                    JOptionPane.WARNING_MESSAGE);   // Alert user if no file was chosen
            return;
        }

        setStatus("Analysing document...", INDIGO);   // Update status before launching worker

        SwingWorker<AnalysisResult, Void> worker = new SwingWorker<>() {

            // -------- Background Task: Text Extraction and Metric Computation --------
            @Override protected AnalysisResult doInBackground() throws Exception {
                return analyzeFile(selectedFile);   // Extract text, count pages, compute all 12 stats
            }

            // -------- EDT Callback: Populate UI with Results --------
            @Override protected void done() {
                try {
                    lastResult = get();              // Retrieve result from background thread
                    showResult(lastResult);          // Push all metric values into UI labels
                    setStatus("Done! All 12 metrics are ready on the right \u2192", SUCCESS);
                } catch (Exception ex) {
                    JOptionPane.showMessageDialog(Main.this,
                            "Could not analyze the file.\n\n" + ex.getMessage(),
                            "Analysis Error", JOptionPane.ERROR_MESSAGE);
                    setStatus("Analysis failed. Please try again.", DANGER);
                }
            }

        };
        worker.execute();   // Start background thread

    }

    // --- CLEAR ALL ---
    // Resets all state variables, metric labels, file info labels, drop area, and status

    private void clearAll() {

        // -------- State Reset --------
        selectedFile = null;    // Clear selected file reference
        lastResult   = null;    // Clear analysis result reference

        // -------- File Info Labels Reset --------
        fileNameValue.setText("-");   // Clear file name pill
        fileTypeValue.setText("-");   // Clear file type pill
        fileSizeValue.setText("-");   // Clear file size pill

        // -------- Metric Labels Reset --------
        charCountValue.setText("-");           // Reset character count
        wordCountValue.setText("-");           // Reset word count
        sentenceCountValue.setText("-");       // Reset sentence count
        paragraphCountValue.setText("-");      // Reset paragraph count
        smallestWordValue.setText("-");        // Reset smallest word
        longestWordValue.setText("-");         // Reset longest word
        uniqueWordsValue.setText("-");         // Reset unique word count
        frequentWordValue.setText("-");        // Reset most repeated word
        avgWordLengthValue.setText("-");       // Reset avg word length
        avgSentenceLengthValue.setText("-");   // Reset avg sentence length
        avgParagraphLengthValue.setText("-");  // Reset avg paragraph length
        totalPagesValue.setText("-");          // Reset page count

        // -------- UI State Reset --------
        dropArea.showPrompt();   // Restore original drag-and-drop prompt view
        setStatus("Cleared. No file uploaded.", TEXT_SECONDARY);

    }

    // --- EXIT HANDLER ---
    // Shows "Exiting..." in status bar for 2 seconds before closing the window

    private void triggerExit() {

        setStatus("Exiting...", DANGER);   // Red dot status indicating exit in progress

        Timer t = new Timer(2000, e -> dispose());   // Close window after 2 second delay
        t.setRepeats(false);
        t.start();

    }

    // --- STATUS SETTER ---
    // Updates the status label with a colored bullet dot prefix and the given message
    // Note: The bullet character \u25CF is a filled circle used as a status dot indicator

    private void setStatus(String message, Color color) {

        statusLabel.setText("  \u25CF  " + message);   // Prepend colored bullet dot to message
        statusLabel.setForeground(color);               // Apply status-specific color

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  ANALYSIS LOGIC
    // ═════════════════════════════════════════════════════════════════════════

    // --- DOCUMENT ANALYSIS COORDINATOR ---
    // Orchestrates text extraction, page counting, and stat computation for a file
    // Note: Runs entirely on a background SwingWorker thread — never on the EDT

    private AnalysisResult analyzeFile(File file) throws Exception {

        // -------- File Metadata --------
        String ext      = getExtension(file).toLowerCase(Locale.ROOT);   // Normalize extension to lowercase
        String text     = extractText(file, ext);                         // Extract raw text from document
        int    pages    = extractPageCount(file, ext);                    // Get page count (PDF only)
        long   sizBytes = Files.size(file.toPath());                      // Get file size in bytes

        // -------- Stats Computation --------
        WordStats stats = computeStats(text);   // Compute all 12 text intelligence metrics

        return new AnalysisResult(
                file.getName(), ext, sizBytes,
                stats.wordCount, stats.characterCount,
                stats.sentenceCount, stats.paragraphCount,
                stats.uniqueWordCount,
                stats.longestWord, stats.smallestWord,
                stats.averageWordLength,
                stats.mostFrequentWord, stats.mostFrequentCount,
                stats.avgSentenceLengthWords, stats.avgSentenceLengthLines,
                stats.avgParaLengthSentences, stats.avgParaLengthLines,
                pages);

    }

    // --- TEXT EXTRACTOR ---
    // Delegates to the appropriate library depending on file extension
    // Note: TXT uses NIO, PDF uses PDFBox, Office formats use Apache POI

    private String extractText(File file, String ext) throws Exception {

        if ("txt".equals(ext))
            return Files.readString(file.toPath(), StandardCharsets.UTF_8);   // Read plain text with UTF-8 encoding

        if ("pdf".equals(ext)) {
            try (var doc = Loader.loadPDF(file)) {
                PDFTextStripper s = new PDFTextStripper();
                s.setSortByPosition(true);   // Sort text by page position for correct reading order
                return s.getText(doc);
            }
        }

        if ("docx".equals(ext) || "xlsx".equals(ext) || "pptx".equals(ext)) {
            try (POITextExtractor ex = ExtractorFactory.createExtractor(file)) {
                return ex.getText();   // Apache POI handles all three Office formats uniformly
            }
        }

        throw new IllegalArgumentException("Unsupported file type: " + ext);   // Reject unknown formats

    }

    // --- PAGE COUNT EXTRACTOR ---
    // Returns actual page count for PDF documents; returns -1 for all other formats
    // Note: -1 is displayed as "N/A" in the UI by showResult()

    private int extractPageCount(File file, String ext) {

        if ("pdf".equals(ext)) {
            try (var doc = Loader.loadPDF(file)) { return doc.getNumberOfPages(); }
            catch (Exception ignored) {}
        }
        return -1;   // Non-PDF formats have no meaningful page count

    }

    // --- TEXT STATS COMPUTATION ---
    // Scans the normalized text string and computes all 12 word, sentence, and paragraph metrics
    // Note: Uses regex pattern matching for word extraction, string splitting for sentence/paragraph counts

    private WordStats computeStats(String text) {

        // -------- Text Normalization --------
        String n = (text == null) ? "" : text.replace('\u00A0', ' ');   // Replace non-breaking spaces with regular spaces

        // -------- Word-Level Analysis --------
        Pattern wp = Pattern.compile("[\\p{L}\\p{N}']+");  // Match words: letters, numbers, apostrophes
        Matcher m  = wp.matcher(n);

        int wc = 0, twc = 0, cc = n.length();   // Word count, total word chars, total char count
        String lw = "", sw = null;                // Longest word, smallest word
        Map<String, Integer> freq = new HashMap<>();   // Word frequency map (lowercase keys)

        while (m.find()) {
            String w = m.group(); wc++; twc += w.length();
            if (w.length() > lw.length()) lw = w;                           // Update longest word
            if (sw == null || w.length() < sw.length()) sw = w;             // Update smallest word
            freq.merge(w.toLowerCase(Locale.ROOT), 1, Integer::sum);        // Increment frequency count
        }

        if (sw == null) sw = "-";   // Default if no words were found

        // -------- Most Frequent Word --------
        String fw = "-"; int fc = 0;
        for (var e : freq.entrySet()) if (e.getValue() > fc) { fw = e.getKey(); fc = e.getValue(); }

        double awl = wc == 0 ? 0 : (double) twc / wc;   // Average word length in characters

        // -------- Sentence Counting --------
        // Split on punctuation followed by whitespace or end of string
        int sc = 0; for (String s : n.split("[.!?]+(?:\\s|$)")) if (!s.isBlank()) sc++;
        if (sc == 0) sc = 1;   // Ensure minimum of 1 to avoid division by zero

        // -------- Line Counting --------
        int lc = 0; for (String l : n.split("\\n")) if (!l.isBlank()) lc++;
        if (lc == 0) lc = 1;   // Ensure minimum of 1

        // -------- Paragraph Counting --------
        // Paragraphs are separated by one or more blank lines
        int pc = 0; for (String p : n.split("\\n\\s*\\n")) if (!p.isBlank()) pc++;
        if (pc == 0) pc = 1;   // Ensure minimum of 1

        // -------- Derived Averages --------
        return new WordStats(wc, cc, freq.size(), lw, sw, awl, fw, fc, sc, pc,
                (double) wc/sc,   // Average sentence length in words
                (double) lc/sc,   // Average sentence length in lines
                (double) sc/pc,   // Average paragraph length in sentences
                (double) lc/pc);  // Average paragraph length in lines

    }

    // --- RESULT DISPLAY ---
    // Pushes all computed metric values from an AnalysisResult into the corresponding UI labels

    private void showResult(AnalysisResult r) {

        // -------- File Info Pills Update --------
        fileNameValue.setText(r.fileName);                               // Display full file name
        fileTypeValue.setText(r.extension.toUpperCase(Locale.ROOT));     // Uppercase extension
        fileSizeValue.setText(formatBytes(r.sizeBytes));                 // Formatted file size

        // -------- Format Templates --------
        DecimalFormat df2 = new DecimalFormat("0.00");   // Two decimal places for averages
        DecimalFormat df1 = new DecimalFormat("0.0");    // One decimal place for sentence/paragraph averages

        // -------- Metric Tile Population --------
        charCountValue.setText(String.valueOf(r.characterCount));    // Display total character count
        wordCountValue.setText(String.valueOf(r.wordCount));         // Display total word count
        sentenceCountValue.setText(String.valueOf(r.sentenceCount)); // Display total sentence count
        paragraphCountValue.setText(String.valueOf(r.paragraphCount)); // Display total paragraph count

        smallestWordValue.setText(r.smallestWord.isBlank()  ? "-" : r.smallestWord);   // Guard empty result
        longestWordValue.setText(r.longestWord.isBlank()    ? "-" : r.longestWord);    // Guard empty result

        uniqueWordsValue.setText(String.valueOf(r.uniqueWordCount));   // Display unique word count
        frequentWordValue.setText(r.mostFrequentWord + " (" + r.mostFrequentCount + ")");  // e.g. "the (83)"

        avgWordLengthValue.setText(df2.format(r.averageWordLength) + " characters");   // e.g. "4.83 characters"
        avgSentenceLengthValue.setText(
                df1.format(r.avgSentenceLengthWords) + " words, "
                + df1.format(r.avgSentenceLengthLines) + " lines");    // e.g. "25.9 words, 4.0 lines"
        avgParagraphLengthValue.setText(
                df1.format(r.avgParaLengthSentences) + " sentences, "
                + df1.format(r.avgParaLengthLines)   + " lines");      // e.g. "54.0 sentences, 216.0 lines"

        totalPagesValue.setText(r.totalPages < 0 ? "N/A" : String.valueOf(r.totalPages));  // N/A for non-PDF

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  UTILITIES
    // ═════════════════════════════════════════════════════════════════════════

    // --- FILE EXTENSION EXTRACTOR ---
    // Returns the file extension without the dot, or empty string if none found

    private String getExtension(File file) {

        String name = file.getName();
        int dot = name.lastIndexOf('.');
        return dot >= 0 ? name.substring(dot + 1) : "";   // Return extension or empty string

    }

    // --- BYTE FORMATTER ---
    // Converts a raw byte count into a human-readable B / KB / MB string

    private String formatBytes(long bytes) {

        DecimalFormat df = new DecimalFormat("0.00");
        if (bytes < 1024) return bytes + " B";           // Display in bytes
        double kb = bytes / 1024.0;
        if (kb < 1024) return df.format(kb) + " KB";     // Display in kilobytes
        return df.format(kb / 1024.0) + " MB";           // Display in megabytes

    }

    // --- FILE TYPE COLOR RESOLVER ---
    // Maps a file extension string to its corresponding brand accent color
    // Note: Used by DropAreaPanel to colorize the file icon for non-PDF uploads

    private static Color fileTypeColor(String ext) {

        return switch (ext.toLowerCase(Locale.ROOT)) {
            case "pdf"  -> new Color(239, 68, 68);    // Red   — PDF brand color
            case "docx" -> new Color(37, 99, 235);    // Blue  — Microsoft Word brand color
            case "xlsx" -> new Color(22, 163, 74);    // Green — Microsoft Excel brand color
            case "pptx" -> new Color(234, 88, 12);    // Orange — Microsoft PowerPoint brand color
            case "txt"  -> new Color(100, 116, 139);  // Gray  — Plain text neutral color
            default     -> new Color(99, 102, 241);   // Indigo — Generic fallback
        };

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  UI COMPONENT FACTORIES
    // ═════════════════════════════════════════════════════════════════════════

    // --- INFO PILL FACTORY ---
    // Creates a rounded panel with a label title (top) and dynamic value label (center)
    // Note: BorderLayout CENTER stretches the value label to fill the full pill width

    private JPanel infoPill(String title, JLabel value, Color accent) {

        RoundedPanel pill = new RoundedPanel();
        pill.setLayout(new BorderLayout(0, 3));   // 3px vertical gap between title and value
        pill.setBorder(new CompoundBorder(
                new LineBorder(new Color(accent.getRed(), accent.getGreen(), accent.getBlue(), 55), 1, true),  // Tinted border
                new EmptyBorder(10, 12, 10, 12)));   // Inner padding
        pill.setBackground(INNER_BG);

        JLabel titleLabel = new JLabel(title);
        titleLabel.setForeground(TEXT_SECONDARY);   // Muted label color
        titleLabel.setFont(FONT_LABEL);

        value.setForeground(TEXT_PRIMARY);   // Bold dark value text
        value.setFont(FONT_VALUE);

        pill.add(titleLabel, BorderLayout.NORTH);    // Label pinned to top
        pill.add(value,      BorderLayout.CENTER);   // Value fills remaining space (stretches full width)
        return pill;

    }

    // --- METRIC TILE FACTORY (STANDARD) ---
    // Creates a standard metric tile with large 18pt value font for short values

    private JPanel metricTile(String title, JLabel value, Color accent) {
        return buildTile(title, value, accent, 18);   // Use large font for single-word or number values
    }

    // --- METRIC TILE FACTORY (COMPACT) ---
    // Creates a compact metric tile with smaller 13pt value font for longer string values

    private JPanel metricTileSm(String title, JLabel value, Color accent) {
        return buildTile(title, value, accent, 13);   // Use smaller font for multi-word values like averages
    }

    // --- TILE BUILDER (SHARED) ---
    // Builds the rounded tile with a colored left stripe, label, and value
    // Note: Called by both metricTile() and metricTileSm() with different font sizes

    private JPanel buildTile(String title, JLabel value, Color accent, int vSize) {

        RoundedPanel tile = new RoundedPanel();
        tile.setLayout(new BorderLayout(8, 8));   // 8px gap between stripe and content
        tile.setBorder(new CompoundBorder(
                new LineBorder(new Color(accent.getRed(), accent.getGreen(), accent.getBlue(), 55), 1, true),  // Tinted accent border
                new EmptyBorder(12, 12, 12, 12)));   // Inner tile padding
        tile.setBackground(INNER_BG);

        // -------- Left Accent Stripe --------
        JPanel stripe = new JPanel();
        stripe.setPreferredSize(new Dimension(7, 0));   // 7px wide vertical stripe
        stripe.setBackground(accent);                    // Filled with tile's accent color

        // -------- Tile Label and Value --------
        JLabel titleLabel = new JLabel(title);
        titleLabel.setForeground(TEXT_SECONDARY);   // Muted label color
        titleLabel.setFont(FONT_LABEL);

        value.setForeground(TEXT_PRIMARY);                          // Bold dark value text
        value.setFont(new Font("Segoe UI", Font.BOLD, vSize));      // Font size varies by tile type

        JPanel content = new JPanel(new BorderLayout(0, 4));   // 4px gap between label and value
        content.setOpaque(false);
        content.add(titleLabel, BorderLayout.NORTH);    // Label pinned to top of content
        content.add(value,      BorderLayout.CENTER);   // Value fills remaining content space

        tile.add(stripe,  BorderLayout.WEST);    // Accent stripe on left edge
        tile.add(content, BorderLayout.CENTER);  // Label+value fills rest of tile
        return tile;

    }

    // --- FORMAT CHIP FACTORY ---
    // Creates a small rounded pill showing a supported file format label
    // Note: Used in the header row to indicate TXT / PDF / DOCX / XLSX / PPTX support

    private JPanel chip(String text, Color bg, Color fg) {

        RoundedPanel p = new RoundedPanel();
        p.setBorder(new EmptyBorder(6, 12, 6, 12));   // Compact horizontal padding
        p.setBackground(bg);                           // Semi-transparent white background on header

        JLabel l = new JLabel(text);
        l.setForeground(fg);                           // White text on dark header background
        l.setFont(new Font("Segoe UI", Font.BOLD, 11));
        p.add(l);
        return p;

    }

    // --- HERO STAT FACTORY ---
    // Creates a small stat card used in the header's 2×2 grid with an accent stripe and two lines of text

    private JPanel heroStat(String title, String subtitle, Color accent) {

        RoundedPanel p = new RoundedPanel();
        p.setLayout(new BorderLayout(8, 8));   // 8px gap between stripe and text content
        p.setBorder(new CompoundBorder(
                new LineBorder(new Color(255, 255, 255, 60), 1, true),   // Semi-transparent white border
                new EmptyBorder(12, 12, 12, 12)));
        p.setBackground(new Color(255, 255, 255, 28));   // Very faint white overlay on dark header

        // -------- Left Accent Stripe --------
        JPanel stripe = new JPanel();
        stripe.setPreferredSize(new Dimension(5, 0));   // 5px wide vertical stripe
        stripe.setBackground(accent);

        // -------- Title and Subtitle --------
        JLabel tl = new JLabel(title);
        tl.setForeground(Color.WHITE);
        tl.setFont(new Font("Segoe UI", Font.BOLD, 13));

        JLabel sl = new JLabel(subtitle);
        sl.setForeground(new Color(203, 213, 225));   // Slate-300 — softer subtitle on dark background
        sl.setFont(new Font("Segoe UI", Font.PLAIN, 12));

        JPanel c = new JPanel();
        c.setOpaque(false);
        c.setLayout(new BoxLayout(c, BoxLayout.Y_AXIS));   // Stack title above subtitle
        c.add(tl);
        c.add(Box.createVerticalStrut(2));   // Tiny gap between title and subtitle
        c.add(sl);

        p.add(stripe, BorderLayout.WEST);    // Accent stripe on left
        p.add(c,      BorderLayout.CENTER);  // Text content fills rest
        return p;

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  DRAG AND DROP
    // ═════════════════════════════════════════════════════════════════════════

    // ===================== FileDropHandler Class =====================

    // --- DRAG AND DROP HANDLER ---
    // Accepts file drops on the DropAreaPanel and passes the first dropped file to setSelectedFile()
    // Note: Only processes the first file if multiple files are dropped simultaneously

    private final class FileDropHandler extends TransferHandler {

        // --- CAN IMPORT CHECK ---
        // Returns true only if the dragged data contains a file list flavor

        @Override public boolean canImport(TransferSupport s) {
            return s.isDataFlavorSupported(DataFlavor.javaFileListFlavor);   // Accept file drops only
        }

        // --- IMPORT DATA ---
        // Extracts the first file from the drop and delegates to setSelectedFile()

        @Override public boolean importData(TransferSupport s) {
            if (!canImport(s)) return false;
            try {
                Object data = s.getTransferable().getTransferData(DataFlavor.javaFileListFlavor);
                if (data instanceof List<?> files && !files.isEmpty()
                        && files.get(0) instanceof File f) {
                    setSelectedFile(f);   // Handle the dropped file as a normal selection
                    return true;
                }
            } catch (Exception ignored) {}
            return false;
        }

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  DATA CLASSES
    // ═════════════════════════════════════════════════════════════════════════

    // ===================== WordStats Class =====================

    // --- WORD STATS DATA HOLDER ---
    // Immutable record of all computed text metrics passed from computeStats() to analyzeFile()
    // Note: Short parameter names in constructor are used intentionally for concise initialization

    private static final class WordStats {

        // --- FIELDS ---
        final int wordCount, characterCount, uniqueWordCount, sentenceCount, paragraphCount;
        final String longestWord, smallestWord, mostFrequentWord;
        final int mostFrequentCount;
        final double averageWordLength, avgSentenceLengthWords, avgSentenceLengthLines;
        final double avgParaLengthSentences, avgParaLengthLines;

        // --- CONSTRUCTOR ---
        // Assigns all computed values using short variable names for readability

        WordStats(int wc, int cc, int uw, String lw, String sw, double awl,
                  String fw, int fc, int sc, int pc,
                  double aslw, double asll, double apls, double apll) {
            wordCount=wc; characterCount=cc; uniqueWordCount=uw;
            longestWord=lw; smallestWord=sw; averageWordLength=awl;
            mostFrequentWord=fw; mostFrequentCount=fc;
            sentenceCount=sc; paragraphCount=pc;
            avgSentenceLengthWords=aslw; avgSentenceLengthLines=asll;
            avgParaLengthSentences=apls; avgParaLengthLines=apll;
        }

    }

    // ===================== AnalysisResult Class =====================

    // --- ANALYSIS RESULT DATA HOLDER ---
    // Immutable record combining file metadata with all WordStats metrics
    // Note: Returned by analyzeFile() and stored in lastResult for potential future use

    private static final class AnalysisResult {

        // --- FIELDS ---
        final String fileName, extension;
        final long sizeBytes;
        final int wordCount, characterCount, sentenceCount, paragraphCount, uniqueWordCount;
        final String longestWord, smallestWord, mostFrequentWord;
        final int mostFrequentCount, totalPages;
        final double averageWordLength, avgSentenceLengthWords, avgSentenceLengthLines;
        final double avgParaLengthSentences, avgParaLengthLines;

        // --- CONSTRUCTOR ---
        // Assigns all file and text metric values using short variable names for readability

        AnalysisResult(String fn, String ext, long sb, int wc, int cc, int sc, int pc,
                       int uw, String lw, String sw, double awl, String fw, int fc,
                       double aslw, double asll, double apls, double apll, int tp) {
            fileName=fn; extension=ext; sizeBytes=sb;
            wordCount=wc; characterCount=cc; sentenceCount=sc; paragraphCount=pc;
            uniqueWordCount=uw; longestWord=lw; smallestWord=sw; averageWordLength=awl;
            mostFrequentWord=fw; mostFrequentCount=fc;
            avgSentenceLengthWords=aslw; avgSentenceLengthLines=asll;
            avgParaLengthSentences=apls; avgParaLengthLines=apll; totalPages=tp;
        }

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  PROPORTIONAL LAYOUT — the definitive card-size fix
    // ═════════════════════════════════════════════════════════════════════════

    // ===================== ProportionalLayout Class =====================

    // --- PROPORTIONAL LAYOUT MANAGER ---
    // Custom LayoutManager that directly calls setBounds() from the container's actual pixel width
    // Key Features:
    //   - Enforces a strict leftRatio / (1-leftRatio) split at all times
    //   - Content can never push a cell wider because bounds are set top-down
    //   - Returns Dimension(0,0) for preferred/minimum to prevent parent inflation
    // Note: GridBagLayout weightx fails here because it distributes only extra space after
    //       preferred widths are satisfied — this layout bypasses preferred widths entirely

    private static final class ProportionalLayout implements LayoutManager {

        private final float leftRatio;   // Fraction of width given to the left child (e.g. 0.42)
        private final int   gap;         // Pixel gap between left and right children

        // --- CONSTRUCTOR ---
        // Stores the left column ratio and the pixel gap between columns

        ProportionalLayout(float leftRatio, int gap) {
            this.leftRatio = leftRatio;
            this.gap = gap;
        }

        // --- REQUIRED INTERFACE STUBS ---
        // Not used in this layout; all sizing is handled in layoutContainer()

        @Override public void addLayoutComponent(String name, Component c) {}
        @Override public void removeLayoutComponent(Component c) {}
        @Override public Dimension preferredLayoutSize(Container p) { return new Dimension(0, 0); }  // Prevent parent growth
        @Override public Dimension minimumLayoutSize(Container p)   { return new Dimension(0, 0); }  // Prevent parent shrink constraint

        // --- LAYOUT CONTAINER ---
        // Directly computes and assigns pixel bounds to both children from actual container dimensions
        // Note: Sets child[0] to leftRatio% and child[1] to the remaining width minus the gap

        @Override public void layoutContainer(Container parent) {

            Insets ins = parent.getInsets();
            int w = parent.getWidth()  - ins.left - ins.right;   // Available container width
            int h = parent.getHeight() - ins.top  - ins.bottom;  // Available container height
            if (w <= 0 || h <= 0) return;                         // Skip layout if container has no size

            Component[] c = parent.getComponents();
            if (c.length < 2) return;   // Require exactly two children

            int lw = Math.max(0, (int)(w * leftRatio) - gap / 2);   // Left child width (42% minus half gap)
            int rw = Math.max(0, w - lw - gap);                      // Right child width (remainder minus gap)
            c[0].setBounds(ins.left,            ins.top, lw, h);     // Set left child bounds directly
            c[1].setBounds(ins.left + lw + gap, ins.top, rw, h);     // Set right child bounds directly

        }

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  CUSTOM PAINT PANELS
    // ═════════════════════════════════════════════════════════════════════════

    // ===================== GradientBackgroundPanel Class =====================

    // --- GRADIENT BACKGROUND PANEL ---
    // Transparent JPanel that paints the app-wide soft slate gradient and two soft oval accents

    private static class GradientBackgroundPanel extends JPanel {

        GradientBackgroundPanel(LayoutManager l) { super(l); setOpaque(false); }

        // --- PAINT COMPONENT ---
        // Fills the panel with a top-to-bottom slate gradient then overlays two decorative ovals

        @Override protected void paintComponent(Graphics g) {

            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            // Slate gradient background (full window)
            g2.setPaint(new GradientPaint(0, 0, APP_BG_TOP, 0, getHeight(), APP_BG_BOTTOM));
            g2.fillRect(0, 0, getWidth(), getHeight());

            // Decorative oval accents (semi-transparent slate, top-right and bottom-left)
            g2.setColor(new Color(226, 232, 240, 80));
            g2.fillOval(getWidth()-260, 20, 240, 240);     // Top-right decorative circle
            g2.fillOval(-80, getHeight()-220, 240, 240);   // Bottom-left decorative circle

            g2.dispose();
            super.paintComponent(g);

        }

    }

    // ===================== GradientHeaderPanel Class =====================

    // --- GRADIENT HEADER PANEL ---
    // Paints the deep navy gradient header bar with two indigo glow oval accents on the right side

    private static class GradientHeaderPanel extends JPanel {

        GradientHeaderPanel(LayoutManager l) { super(l); setOpaque(false); }

        // --- PAINT COMPONENT ---
        // Fills a rounded rectangle with the navy gradient, then overlays two layered indigo glow ovals

        @Override protected void paintComponent(Graphics g) {

            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            int w = getWidth(), h = getHeight();

            // Main dark navy gradient (slate-900 to slate-800)
            g2.setPaint(new GradientPaint(0, 0, HEADER_START, w, h, HEADER_MID));
            g2.fillRoundRect(0, 0, w, h, 28, 28);   // Rounded header shape

            // Inner indigo glow (stronger, smaller oval close to top-right)
            g2.setColor(new Color(HEADER_GLOW.getRed(), HEADER_GLOW.getGreen(), HEADER_GLOW.getBlue(), 50));
            g2.fillOval(w-210, -90, 300, 300);

            // Outer indigo halo (softer, larger oval behind the inner glow)
            g2.setColor(new Color(HEADER_GLOW.getRed(), HEADER_GLOW.getGreen(), HEADER_GLOW.getBlue(), 18));
            g2.fillOval(w-400, -110, 400, 400);

            g2.dispose();
            super.paintComponent(g);

        }

    }

    // ===================== CardPanel Class =====================

    // --- CARD PANEL ---
    // Base panel for all three main cards (Upload, Buttons, Analysis)
    // Note: Paints a pure white rounded rectangle as the card background

    private static class CardPanel extends JPanel {

        CardPanel() { super(new BorderLayout()); setOpaque(false); }

        // --- PAINT COMPONENT ---
        // Fills the entire card area with a white rounded rectangle

        @Override protected void paintComponent(Graphics g) {

            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setColor(CARD_BG);   // Pure white card background
            g2.fillRoundRect(0, 0, getWidth(), getHeight(), 24, 24);   // Rounded card corners
            g2.dispose();
            super.paintComponent(g);

        }

    }

    // ===================== RoundedPanel Class =====================

    // --- ROUNDED PANEL ---
    // Generic reusable panel that paints its background as a rounded rectangle
    // Note: Used for metric tiles, info pills, format chips, and hero stat cards

    private static class RoundedPanel extends JPanel {

        RoundedPanel() { super(new BorderLayout()); setOpaque(false); }

        // --- PAINT COMPONENT ---
        // Fills the panel with its assigned background color in a rounded rectangle shape

        @Override protected void paintComponent(Graphics g) {

            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setColor(getBackground());   // Use whatever background color was set externally
            g2.fillRoundRect(0, 0, getWidth(), getHeight(), 22, 22);
            g2.dispose();
            super.paintComponent(g);

        }

    }


    // ═════════════════════════════════════════════════════════════════════════
    //  DROP AREA PANEL — switches between PROMPT, LOADING, and THUMBNAIL views
    // ═════════════════════════════════════════════════════════════════════════

    // ===================== DropAreaPanel Class =====================

    // --- DROP AREA PANEL ---
    // Inner panel that uses CardLayout to switch between three visual states:
    //   PROMPT  — Default drag-and-drop invitation shown before any file is selected
    //   LOADING — Temporary view shown while PDF thumbnail is being rendered
    //   THUMB   — Document thumbnail (PDF page preview) or file type icon after selection
    // Note: showPrompt(), showLoading(), showThumbnail() are called from the outer class

    private final class DropAreaPanel extends JPanel {

        // --- CARD NAME CONSTANTS ---
        private static final String CARD_PROMPT  = "PROMPT";    // Default drag-and-drop prompt view
        private static final String CARD_LOADING = "LOADING";   // Temporary "Loading preview..." view
        private static final String CARD_THUMB   = "THUMB";     // Document thumbnail or file icon view

        // --- FIELDS ---
        private final CardLayout  cards    = new CardLayout();   // Manages which view is currently shown
        private final JPanel      thumbCard;                     // Custom-painted thumbnail card (declared as field for repaint access)

        private BufferedImage thumbnail = null;   // PDF page image (null for non-PDF files)
        private String        thumbName = "";     // File name shown in bottom bar of thumbnail view
        private String        thumbExt  = "";     // Extension used to select file type icon color

        // --- CONSTRUCTOR ---
        // Builds all three cards and adds them to the CardLayout container

        DropAreaPanel() {

            setOpaque(false);
            setLayout(cards);

            // -------- PROMPT Card --------
            // Shown on startup and after Clear — invites user to drag or browse
            JPanel promptCard = new JPanel(new BorderLayout(10, 10));
            promptCard.setOpaque(false);
            promptCard.setBorder(new CompoundBorder(
                    new DashedBorder(new Color(148, 163, 184), 1.5f, 8f),   // Slate-400 dashed border
                    new EmptyBorder(18, 18, 18, 18)));
            promptCard.setBackground(INNER_BG);

            JLabel icon = new JLabel("\u2B06", SwingConstants.CENTER);   // Upward arrow icon
            icon.setFont(new Font("Segoe UI Symbol", Font.BOLD, 24));
            icon.setForeground(INDIGO);   // Indigo arrow matches header glow color

            JLabel pt = new JLabel(
                    "<html><center><b>Drag &amp; Drop your document</b><br/>"
                    + "or use the Browse button below</center></html>",
                    SwingConstants.CENTER);
            pt.setForeground(TEXT_PRIMARY);
            pt.setFont(new Font("Segoe UI", Font.PLAIN, 14));

            JLabel ph = new JLabel("Supported: .txt, .pdf, .docx, .xlsx, .pptx",
                    SwingConstants.CENTER);
            ph.setForeground(TEXT_SECONDARY);
            ph.setFont(new Font("Segoe UI", Font.PLAIN, 12));

            JPanel inner = new JPanel();
            inner.setOpaque(false);
            inner.setLayout(new BoxLayout(inner, BoxLayout.Y_AXIS));   // Stack icon and text vertically
            icon.setAlignmentX(Component.CENTER_ALIGNMENT);
            pt.setAlignmentX(Component.CENTER_ALIGNMENT);
            ph.setAlignmentX(Component.CENTER_ALIGNMENT);
            inner.add(icon);
            inner.add(Box.createVerticalStrut(6));   // Gap between icon and title text
            inner.add(pt);
            inner.add(Box.createVerticalStrut(4));   // Gap between title and hint text
            inner.add(ph);
            promptCard.add(inner, BorderLayout.CENTER);

            // -------- LOADING Card --------
            // Shown immediately after file selection while background PDF rendering runs
            JPanel loadingCard = new JPanel(new BorderLayout());
            loadingCard.setOpaque(false);
            loadingCard.setBorder(new CompoundBorder(
                    new DashedBorder(new Color(148, 163, 184), 1.5f, 8f),
                    new EmptyBorder(18, 18, 18, 18)));
            loadingCard.setBackground(INNER_BG);

            JLabel loadingLabel = new JLabel("Loading preview...", SwingConstants.CENTER);
            loadingLabel.setForeground(TEXT_SECONDARY);
            loadingLabel.setFont(new Font("Segoe UI", Font.ITALIC, 13));
            loadingCard.add(loadingLabel, BorderLayout.CENTER);

            // -------- THUMB Card --------
            // Custom-painted panel — draws PDF page image or file type icon + filename bar
            thumbCard = new JPanel() {

                @Override protected void paintComponent(Graphics g) {

                    Graphics2D g2 = (Graphics2D) g.create();
                    g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING,    RenderingHints.VALUE_ANTIALIAS_ON);
                    g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION,   RenderingHints.VALUE_INTERPOLATION_BILINEAR);
                    g2.setRenderingHint(RenderingHints.KEY_RENDERING,       RenderingHints.VALUE_RENDER_QUALITY);

                    int w = getWidth(), h = getHeight();

                    // -------- Background and Border --------
                    g2.setColor(INNER_BG);
                    g2.fillRoundRect(0, 0, w, h, 24, 24);   // Rounded card background

                    g2.setColor(new Color(148, 163, 184));   // Slate-400 dashed border
                    float[] dp = {8f};
                    g2.setStroke(new BasicStroke(1.5f, BasicStroke.CAP_ROUND,
                            BasicStroke.JOIN_ROUND, 10f, dp, 0f));
                    g2.drawRoundRect(2, 2, w-5, h-5, 18, 18);
                    g2.setStroke(new BasicStroke(1));   // Reset stroke

                    int pad = 16, barH = 36;
                    int imgAreaH = h - pad*2 - barH - 6;   // Available height for image above the filename bar

                    if (thumbnail != null) {

                        // -------- PDF Page Thumbnail --------
                        double iw = thumbnail.getWidth(), ih = thumbnail.getHeight();
                        double scale = Math.min((w - pad*2) / iw, imgAreaH / ih);   // Scale to fit within bounds
                        int tw = (int)(iw * scale), th = (int)(ih * scale);
                        int tx = (w - tw) / 2, ty = pad;   // Center horizontally

                        g2.setColor(new Color(0, 0, 0, 25));
                        g2.fillRoundRect(tx+4, ty+4, tw, th, 8, 8);   // Drop shadow offset by 4px

                        g2.drawImage(thumbnail, tx, ty, tw, th, null);   // Draw scaled PDF page

                        g2.setColor(CARD_BORDER);
                        g2.drawRoundRect(tx, ty, tw, th, 6, 6);   // Thin border around page image

                    } else {

                        // -------- Non-PDF File Type Icon --------
                        Color fc = fileTypeColor(thumbExt);   // Get brand color for this extension
                        int iw2 = 72, ih2 = 90;               // Icon dimensions
                        int tx = (w - iw2) / 2, ty = pad + (imgAreaH - ih2) / 2;   // Center icon

                        g2.setColor(new Color(0, 0, 0, 20));
                        g2.fillRoundRect(tx+4, ty+4, iw2, ih2, 12, 12);   // Drop shadow

                        g2.setColor(fc);
                        g2.fillRoundRect(tx, ty, iw2, ih2, 12, 12);   // Colored file icon body

                        // Dog-ear fold corner (top-right triangle)
                        g2.setColor(new Color(255, 255, 255, 50));
                        int[] xs = {tx+iw2-18, tx+iw2, tx+iw2};
                        int[] ys = {ty, ty, ty+18};
                        g2.fillPolygon(xs, ys, 3);   // Triangle fold

                        // Extension label centered on icon
                        g2.setColor(Color.WHITE);
                        Font ef = new Font("Segoe UI", Font.BOLD, 16);
                        g2.setFont(ef);
                        FontMetrics efm = g2.getFontMetrics(ef);
                        String etxt = thumbExt.toUpperCase(Locale.ROOT);
                        g2.drawString(etxt, tx + (iw2 - efm.stringWidth(etxt))/2,
                                ty + ih2/2 + efm.getAscent()/2 - 2);   // Centered on icon face

                    }

                    // -------- Bottom Filename Bar --------
                    // Dark semi-transparent pill at the bottom showing the selected filename
                    int barY = h - barH - 4;
                    g2.setColor(new Color(15, 23, 42, 190));   // Navy at 75% opacity
                    g2.fillRoundRect(pad, barY, w - pad*2, barH, 12, 12);

                    g2.setColor(Color.WHITE);
                    Font nf = new Font("Segoe UI", Font.BOLD, 12);
                    g2.setFont(nf);
                    FontMetrics nfm = g2.getFontMetrics(nf);
                    int maxChars = (w - pad*2 - 20) / (nfm.charWidth('a') + 1);   // Max chars that fit in bar
                    String display = thumbName.length() > maxChars
                            ? thumbName.substring(0, Math.max(0, maxChars-3)) + "..."
                            : thumbName;   // Truncate with ellipsis if filename is too long
                    g2.drawString(display, pad + 10, barY + barH/2 + nfm.getAscent()/2 - 1);

                    // -------- Change Hint Text --------
                    // Small hint in bottom-right corner reminding user they can re-upload
                    Font hf = new Font("Segoe UI", Font.PLAIN, 11);
                    g2.setFont(hf);
                    g2.setColor(new Color(148, 163, 184, 200));   // Muted slate hint color
                    String hint = "Browse or drag to change";
                    FontMetrics hfm = g2.getFontMetrics(hf);
                    g2.drawString(hint, w - hfm.stringWidth(hint) - 10, h - 6);

                    g2.dispose();

                }

            };
            thumbCard.setOpaque(false);

            // -------- Register All Cards with CardLayout --------
            add(promptCard,  CARD_PROMPT);    // Default state
            add(loadingCard, CARD_LOADING);   // Intermediate state
            add(thumbCard,   CARD_THUMB);     // Post-upload state

        }

        // --- SHOW PROMPT ---
        // Switches to the drag-and-drop invitation view (used on startup and after Clear)

        void showPrompt()   { cards.show(this, CARD_PROMPT);  repaint(); }

        // --- SHOW LOADING ---
        // Switches to the "Loading preview..." view (shown while PDF is being rendered)

        void showLoading()  { cards.show(this, CARD_LOADING); repaint(); }

        // --- SHOW THUMBNAIL ---
        // Stores the rendered image and file metadata, then switches to the thumbnail card
        // Note: img is null for non-PDF files; paintComponent draws a file icon instead

        void showThumbnail(BufferedImage img, String name, String ext) {
            this.thumbnail = img;      // null for non-PDF, page 0 image for PDF
            this.thumbName = name;     // Full file name for bottom bar display
            this.thumbExt  = ext;      // Extension for file icon color resolution
            thumbCard.repaint();       // Force redraw with new data
            cards.show(this, CARD_THUMB);
        }

        // --- PAINT COMPONENT (OUTER) ---
        // Paints the container background — only visible during brief CardLayout transitions

        @Override protected void paintComponent(Graphics g) {
            Graphics2D g2 = (Graphics2D) g.create();
            g2.setColor(INNER_BG);
            g2.fillRoundRect(0, 0, getWidth(), getHeight(), 24, 24);
            g2.dispose();
            super.paintComponent(g);
        }

    }

    // ===================== DashedBorder Class =====================

    // --- DASHED BORDER ---
    // Custom Border implementation that draws a rounded dashed outline
    // Note: Used on both the PROMPT and LOADING cards of DropAreaPanel

    private static class DashedBorder implements Border {

        private final Color color;          // Stroke color for the dashed line
        private final float thickness;      // Stroke thickness in pixels
        private final float dash;           // Dash segment length in pixels

        // --- CONSTRUCTOR ---
        // Stores stroke properties for use in paintBorder()

        DashedBorder(Color c, float t, float d) { color=c; thickness=t; dash=d; }

        // --- BORDER INSETS ---
        // Provides 12px padding on all sides inside the dashed rectangle

        @Override public Insets getBorderInsets(Component c) { return new Insets(12,12,12,12); }

        // --- OPAQUE CHECK ---
        // Returns false — border does not fill its insets area with a solid color

        @Override public boolean isBorderOpaque() { return false; }

        // --- PAINT BORDER ---
        // Draws a dashed rounded rectangle using BasicStroke with a float dash pattern

        @Override public void paintBorder(Component c, Graphics g, int x, int y, int w, int h) {

            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
            g2.setColor(color);
            g2.setStroke(new BasicStroke(thickness, BasicStroke.CAP_ROUND,
                    BasicStroke.JOIN_ROUND, 10f, new float[]{dash}, 0f));  // Dash pattern array
            g2.drawRoundRect(x+2, y+2, w-5, h-5, 18, 18);   // Inset slightly to stay within component
            g2.dispose();

        }

    }

    // ===================== StyledButton Class =====================

    // --- STYLED BUTTON ---
    // Custom JButton subclass that paints a gradient fill with a subtle white rim
    // Key Features:
    //   - Gradient shifts to brighter/darker on mouse hover
    //   - Fixed size (145×40) — enforced via preferred, maximum, and minimum sizes
    //   - Used for Browse File, Analyze, Clear, and Exit buttons

    private final class StyledButton extends JButton {

        private final Color baseColor;   // Base color passed in at construction (e.g. PRIMARY, GREEN, DANGER)
        private boolean hover;           // True while mouse is over the button (triggers brighter gradient)

        // --- CONSTRUCTOR ---
        // Configures button appearance and registers a mouse adapter for hover state tracking

        StyledButton(String text, Color baseColor) {

            super(text);
            this.baseColor = baseColor;
            setFont(new Font("Segoe UI", Font.BOLD, 13));
            setForeground(Color.WHITE);                                      // White label text on all buttons
            setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));       // Hand cursor on hover
            setFocusPainted(false);                                          // No focus ring
            setContentAreaFilled(false);                                     // Disable default Swing fill
            setBorderPainted(false);                                         // Disable default Swing border
            setOpaque(false);                                                // Allow custom painting
            setBorder(new EmptyBorder(10, 16, 10, 16));                     // Padding inside button
            setPreferredSize(new Dimension(145, 40));                        // Fixed button size
            setMaximumSize(new Dimension(145, 40));                          // Prevent stretching
            setMinimumSize(new Dimension(100, 40));                          // Minimum reasonable width

            // -------- Hover Tracking --------
            addMouseListener(new java.awt.event.MouseAdapter() {
                @Override public void mouseEntered(java.awt.event.MouseEvent e) { hover=true;  repaint(); }  // Enter — show brighter gradient
                @Override public void mouseExited (java.awt.event.MouseEvent e) { hover=false; repaint(); }  // Exit  — restore normal gradient
            });

        }

        // --- PAINT COMPONENT ---
        // Paints a vertical gradient fill (lighter top, darker bottom) that brightens on hover
        // then draws a semi-transparent white rim for a subtle border effect

        @Override protected void paintComponent(Graphics g) {

            Graphics2D g2 = (Graphics2D) g.create();
            g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

            // -------- Gradient Fill --------
            Color top    = hover ? baseColor.brighter()        : baseColor;               // Top brighter on hover
            Color bottom = hover ? baseColor.darker()          : baseColor.darker().darker();  // Bottom always darker
            g2.setPaint(new GradientPaint(0, 0, top, 0, getHeight(), bottom));
            g2.fillRoundRect(0, 0, getWidth(), getHeight(), 22, 22);

            // -------- White Rim --------
            g2.setColor(new Color(255, 255, 255, 55));   // Semi-transparent white border highlight
            g2.drawRoundRect(0, 0, getWidth()-1, getHeight()-1, 22, 22);

            g2.dispose();
            super.paintComponent(g);   // Paint the button label text on top

        }

    }

}
