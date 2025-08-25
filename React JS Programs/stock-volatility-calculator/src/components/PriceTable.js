/* ===================== PRICE INPUT TABLE GENERATOR ===================== */
/* Dynamically creates price input tables for both companies */

import React from 'react';

function PriceTable({ company1, company2, timeframe, period, onCalculate }) {
  // -------- LOCAL VARIABLES --------
  // Determine label based on timeframe
  const label = timeframe === 'daily' ? 'Day' : 
                timeframe === 'weekly' ? 'Week' : 'Month';
  
  // -------- EVENT HANDLERS --------
  // Calculate statistics from price inputs
  const handleCalculate = () => {
    const c1Prices = [];
    const c2Prices = [];
    
    // Collect price values from input fields
    for (let i = 1; i <= period; i++) {
      const c1Input = document.getElementById(`c1_${i}`);
      const c2Input = document.getElementById(`c2_${i}`);
      
      // Validation: Ensure all fields are filled
      if (!c1Input.value || !c2Input.value) {
        alert("Please fill all price fields");
        return;
      }
      
      // Store prices
      c1Prices.push(parseFloat(c1Input.value));
      c2Prices.push(parseFloat(c2Input.value));
    }
    
    // Pass prices to parent component
    onCalculate({ c1Prices, c2Prices });
  };

  // -------- TABLE GENERATION --------
  // Create input rows for specified periods
  const rows = [];
  for (let i = 1; i <= period; i++) {
    rows.push(
      <tr key={i}>
        <td>{label} {i}</td>                     {/* Period label */}
        <td><input type="number" id={`c1_${i}`} /></td> {/* Company 1 price */}
        <td><input type="number" id={`c2_${i}`} /></td> {/* Company 2 price */}
      </tr>
    );
  }

  // -------- COMPONENT RENDERING --------
  return (
    <div className="table-section">
      <div id="tableContainer">
        <table>
          <thead>
            <tr>
              <th>{label}</th>               {/* Time period column */}
              <th>{company1} Price</th>      {/* Company 1 header */}
              <th>{company2} Price</th>      {/* Company 2 header */}
            </tr>
          </thead>
          <tbody>
            {rows}  {/* Dynamically generated input rows */}
          </tbody>
        </table>
      </div>
      
      {/* Calculate Button */}
      <div className="calculate-button-container">
        <button id="calcButton" onClick={handleCalculate}>Calculate Stats</button>
      </div>
    </div>
  );
}

export default PriceTable;