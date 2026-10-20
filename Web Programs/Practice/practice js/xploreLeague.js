// Generate the matrix when the user clicks Generate Matrix

document.getElementById("generateBtn").addEventListener("click", function () {

    const rowsValue = document.getElementById("rows").value;
    const colsValue = document.getElementById("cols").value;

    const rows = Number(rowsValue);
    const cols = Number(colsValue);

    const arrayInput = document.getElementById("arrayInput");
    const arrayFields = document.getElementById("arrayFields");

    const solveBtn = document.getElementById("solveBtn");
    const outputSection = document.getElementById("outputSection");
    const outputFields = document.getElementById("outputFields");

    const message = document.getElementById("message");

    // Clear previous matrix, output, and messages

    arrayFields.innerHTML = "";
    outputFields.innerHTML = "";

    outputSection.style.display = "none";
    arrayInput.style.display = "none";
    solveBtn.style.display = "none";

    message.textContent = "";

    // Validate dimensions

    if (
        rowsValue.trim() === "" ||
        colsValue.trim() === "" ||
        !Number.isSafeInteger(rows) ||
        !Number.isSafeInteger(cols) ||
        rows <= 0 ||
        cols <= 0
    ) {
        message.textContent =
            "Please enter valid positive integers for rows and columns.";

        return;
    }

    // Create the matrix input fields

    for (let i = 0; i < rows; i++) {

        const rowDiv = document.createElement("div");

        rowDiv.className = "matrixRow";

        for (let j = 0; j < cols; j++) {

            const input = document.createElement("input");

            input.type = "number";
            input.className = "matrixCell";

            input.id = `cell-${i}-${j}`;

            input.placeholder = `${i + 1},${j + 1}`;

            input.setAttribute(
                "aria-label",
                `Row ${i + 1}, Column ${j + 1}`
            );

            rowDiv.appendChild(input);
        }

        arrayFields.appendChild(rowDiv);
    }

    // Display the matrix and Solve button

    arrayInput.style.display = "block";
    solveBtn.style.display = "inline-block";
});


// Collect matrix values, call the solution function,
// and display the returned 1-D array

document.getElementById("solveBtn").addEventListener("click", function () {

    const rows = Number(document.getElementById("rows").value);
    const cols = Number(document.getElementById("cols").value);

    const outputFields = document.getElementById("outputFields");
    const outputSection = document.getElementById("outputSection");

    const message = document.getElementById("message");

    // Clear previous output and messages

    outputFields.innerHTML = "";
    outputSection.style.display = "none";
    message.textContent = "";

    // Collect the matrix values into a 2-D array

    const inputArray = [];

    for (let i = 0; i < rows; i++) {

        const currentRow = [];

        for (let j = 0; j < cols; j++) {

            const input = document.getElementById(`cell-${i}-${j}`);

            if (input === null || input.value.trim() === "") {

                message.textContent =
                    `Please enter a value at Row ${i + 1}, Column ${j + 1}.`;

                return;
            }

            const value = Number(input.value);

            if (!Number.isSafeInteger(value)) {

                message.textContent =
                    `Please enter a valid integer at Row ${i + 1}, Column ${j + 1}.`;

                return;
            }

            currentRow.push(value);
        }

        inputArray.push(currentRow);
    }

    // Pass the 2-D array to the solution function

    const result = xploreLeagueSolution(inputArray);

    // Validate the returned 1-D integer array

    if (
        !Array.isArray(result) ||
        !result.every(Number.isSafeInteger)
    ) {
        message.textContent =
            "The solution must return a 1-D array of integers.";

        return;
    }

    // Generate the output input boxes

    result.forEach(function (value, index) {

        const outputInput = document.createElement("input");

        outputInput.type = "number";
        outputInput.className = "outputCell";

        outputInput.value = value;
        outputInput.readOnly = true;

        outputInput.setAttribute(
            "aria-label",
            `Output element ${index + 1}`
        );

        outputFields.appendChild(outputInput);
    });

    // Display the Output label and output boxes

    outputSection.style.display = "block";
});


// Problem-solving function

function xploreLeagueSolution(bitArrays) 
{

    let decimalValueArray = [];

    for(let i = 0; i < bitArrays.length; i++) 
    {
        let max = -1;

        for(let j = 0; j < bitArrays[i].length; j++)
        {
            if(max < bitArrays[i][j])
            {
                max = bitArrays[i][j];
            }
        }

        let bitValues = [];

        for(let j = 0; j <= max; j++)
        {
            let bit = 0;
            for(let k = 0; k < bitArrays[i].length; k++)
            {
                if(j == bitArrays[i][k])
                {
                    bit = 1;
                    break;
                }
            }
            bitValues.push(bit);
        }

        let decimalValue = 0;
        let m = 1;

        for(let k = 0; k < bitValues.length; k++)
        {
            decimalValue = decimalValue + bitValues[k] * m;
            m = m * 2;
        }

        decimalValueArray.push(decimalValue);
    }

    let resultArray = [];

    for (let i = 0; i < decimalValueArray.length; i++)
    {
        resultArray.push(i);
    }

    for (let i = 0; i < decimalValueArray.length; i++)
    {
        for(let j = 0; j < decimalValueArray.length - i - 1; j++)
        {
            if(decimalValueArray[j] < decimalValueArray[j + 1])
            {
                let temp = decimalValueArray[j];
                decimalValueArray[j] = decimalValueArray[j + 1];
                decimalValueArray[j + 1] = temp;

                temp = resultArray[j];
                resultArray[j] = resultArray[j + 1];
                resultArray[j + 1] = temp;
            }
        }
    }

    return resultArray;

    /* --- Optimised Solution ---
    let decimalValueArray = [];

    // Step 1: Calculate the decimal value of each row

    for (let i = 0; i < bitArrays.length; i++)
    {
        let decimalValue = 0n;

        for (let j = 0; j < bitArrays[i].length; j++)
        {
            decimalValue = decimalValue | (1n << BigInt(bitArrays[i][j]));
        }

        decimalValueArray.push(decimalValue);
    }


    // Step 2: Create an array containing indices and decimal values

    let resultArray = [];

    for (let i = 0; i < decimalValueArray.length; i++)
    {
        resultArray.push({
            index: i,
            value: decimalValueArray[i]
        });
    }


    // Step 3: Sort in descending order of decimal values

    resultArray.sort(function(a, b) {       // (or) resultArray.sort((a, b) =>
                                            //          (a.value > b.value) ? 1 :
        if (a.value > b.value)              //          (a.value < b.value) ? -1 :
        {                                   //          (a.index - b.index)); 
            return -1;
        }

        if (a.value < b.value)
        {
            return 1;
        }

        return a.index - b.index;
    });


    // Step 4: Extract and return the original indices

    let finalResult = [];

    for (let i = 0; i < resultArray.length; i++)
    {
        finalResult.push(resultArray[i].index);
    }

    return finalResult;
    */
}

/*
PROBLEM: Sort Binary Numbers by Their Decimal Values

PROBLEM STATEMENT:

You are given a two-dimensional array representing binary numbers.
Each row contains the positions of the bits that are set to 1.

The bit positions are zero-based, starting from the rightmost bit.
For each row, construct its binary representation and convert it
to its corresponding decimal value.

Sort these decimal values in descending order while preserving
their original indices.

Return a one-dimensional array containing the original indices
in the order of the sorted decimal values.

INPUT FORMAT:

The first line contains an integer N, representing the number
of rows in the two-dimensional array.

The second line contains an integer M, representing the number
of elements in each row.

The next N lines contain M space-separated integers representing
the positions of the set bits in each binary number.

INPUT:

3
2
0 2
2 3
2 1

INPUT EXPLANATION:

N = 3
M = 2

The given two-dimensional array is:

[
    [0, 2],
    [2, 3],
    [2, 1]
]

Each row represents the positions of bits that must be set to 1.

EXPLANATION:

Consider the following table:

+-------+--------+---------+
| i     | Binary | Decimal |
+-------+--------+---------+
| 0     | 0101   | 5       |
| 1     | 1100   | 12      |
| 2     | 0110   | 6       |
+-------+--------+---------+

The binary values correspond to these decimal values:

0101 = 5
1100 = 12
0110 = 6

Sort the decimal values in descending order.

Before sorting:
5, 12, 6

After sorting:
12, 6, 5

Now identify the original index of each decimal value:

12 belongs to index 1.
6 belongs to index 2.
5 belongs to index 0.

Return the original indices as a one-dimensional array.

OUTPUT:

1 2 0

IMPORTANT:
Return only the original indices, not the decimal values.
*/
