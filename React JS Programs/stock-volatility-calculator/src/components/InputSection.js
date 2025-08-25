/* ===================== USER INPUT SECTION ===================== */
/* Handles company name inputs and analysis parameters selection */

import React, { useState } from 'react';

function InputSection({ onGenerateTable, onReset }) {
  // -------- STATE MANAGEMENT --------
  const [company1, setCompany1] = useState('');   // Company 1 name
  const [company2, setCompany2] = useState('');   // Company 2 name
  const [timeframe, setTimeframe] = useState('daily'); // Analysis timeframe
  const [period, setPeriod] = useState('');       // Number of periods

  // -------- EVENT HANDLERS --------
  // Generate price input table
  const handleGenerate = () => {
    // Input validation
    if (!period || period < 1) {
      alert("Please enter a valid number of periods.");
      return;
    }
    
    // Pass configuration to parent component
    onGenerateTable({
      company1: company1 || "Company 1",  // Default name if empty
      company2: company2 || "Company 2",  // Default name if empty
      timeframe,
      period: parseInt(period)            // Convert to integer
    });
  };

  // -------- COMPONENT RENDERING --------
  return (
    <div className="input-section-container">
      {/* Company Name Inputs */}
      <div className="company-input-group">
        <label htmlFor="company1">Enter Company 1 Name:</label>
        <input 
          type="text" 
          id="company1" 
          placeholder="Company 1" 
          value={company1}
          onChange={(e) => setCompany1(e.target.value)}
        />
        
        <label htmlFor="company2">Enter Company 2 Name:</label>
        <input 
          type="text" 
          id="company2" 
          placeholder="Company 2" 
          value={company2}
          onChange={(e) => setCompany2(e.target.value)}
        />
      </div>

      {/* Analysis Parameters */}
      <div className="controls-group">
        <label htmlFor="timeframe">Select Timeframe:</label>
        <select 
          id="timeframe" 
          value={timeframe}
          onChange={(e) => setTimeframe(e.target.value)}
        >
          <option value="daily">Daily</option>    {/* Daily price analysis */}
          <option value="weekly">Weekly</option>  {/* Weekly price analysis */}
          <option value="monthly">Monthly</option> {/* Monthly price analysis */}
        </select>
        
        <input 
          type="number" 
          id="timeInput" 
          placeholder="Enter number of periods" 
          min="1"
          value={period}
          onChange={(e) => setPeriod(e.target.value)}
        />
        
        {/* Action Buttons */}
        <button onClick={handleGenerate}>Generate Table</button>
        <button onClick={onReset}>Reset</button>
      </div>
    </div>
  );
}

export default InputSection;