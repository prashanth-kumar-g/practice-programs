/* ===================== MAIN APPLICATION COMPONENT ===================== */
/* Serves as the central hub for all components and state management */

import React, { useState } from 'react';
import Header from './components/Header';
import InputSection from './components/InputSection';
import PriceTable from './components/PriceTable';
import ResultsDisplay from './components/ResultsDisplay';
import Equations from './components/Equations';
import Charts from './components/Charts';
import AnalysisReport from './components/AnalysisReport';
import './App.css';

function App() {
  // -------- STATE MANAGEMENT --------
  // Manages the core application state
  const [tableConfig, setTableConfig] = useState(null); // Stores table configuration (company names, timeframe, period)
  const [results, setResults] = useState(null);         // Stores calculated price results
  const [showResults, setShowResults] = useState(false); // Controls results visibility

  // -------- EVENT HANDLERS --------
  // Generates price input table
  const handleGenerateTable = (config) => {
    setTableConfig(config);            // Store table configuration
    setShowResults(false);             // Hide previous results
  };

  // Calculates statistics from price inputs
  const handleCalculate = (prices) => {
    setResults(prices);                // Store calculated prices
    setShowResults(true);              // Show results sections
  };

  // Resets the entire application
  const handleReset = () => {
    setTableConfig(null);              // Clear table config
    setResults(null);                  // Clear calculated results
    setShowResults(false);             // Hide results sections
  };

  // -------- COMPONENT RENDERING --------
  return (
    <div className="App">
      {/* Application Header */}
      <Header />
      
      {/* Main Content Area */}
      <div className="main-content">
        {/* User Input Section */}
        <InputSection 
          onGenerateTable={handleGenerateTable} 
          onReset={handleReset} 
        />
        
        {/* Price Input Table */}
        {tableConfig && (
          <PriceTable 
            {...tableConfig} 
            onCalculate={handleCalculate} 
          />
        )}
        
        {/* Results Display (Conditional Rendering) */}
        {showResults && results && (
          <>
            {/* Statistical Results Tables */}
            <ResultsDisplay 
              company1={tableConfig.company1} 
              company2={tableConfig.company2}
              prices={results}
              period={tableConfig.period}
            />
            
            {/* Mathematical Equations */}
            <Equations 
              company1={tableConfig.company1} 
              company2={tableConfig.company2}
              prices={results}
              period={tableConfig.period}
            />
            
            {/* Interactive Price Charts */}
            <Charts 
              company1={tableConfig.company1} 
              company2={tableConfig.company2}
              prices={results}
              timeframe={tableConfig.timeframe}
            />
            
            {/* Comparative Analysis Report */}
            <AnalysisReport 
              company1={tableConfig.company1} 
              company2={tableConfig.company2}
              prices={results}
              period={tableConfig.period}
            />
          </>
        )}
      </div>
    </div>
  );
}

export default App;