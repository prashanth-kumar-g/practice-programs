/* ===================== STATISTICAL RESULTS DISPLAY ===================== */
/* Shows detailed calculation tables for both companies */

import React from 'react';
import { calculateCompanyStats } from '../utils/calculations';

function ResultsDisplay({ company1, company2, prices, period }) {
  // -------- STATISTICAL CALCULATIONS --------
  // Calculate metrics for both companies
  const stats1 = calculateCompanyStats(prices.c1Prices);
  const stats2 = calculateCompanyStats(prices.c2Prices);

  // -------- HELPER FUNCTIONS --------
  // Generate table rows for a company
  const generateCompanyRows = (prices, mean) => {
    return prices.map((price, index) => {
      const deviation = (price - mean).toFixed(2);  // (x_i - x̄)
      const squared = (deviation ** 2).toFixed(2);  // (x_i - x̄)^2
      return (
        <tr key={index}>
          <td>{price}</td>         {/* Original price */}
          <td>{deviation}</td>     {/* Deviation from mean */}
          <td>{squared}</td>       {/* Squared deviation */}
        </tr>
      );
    });
  };

  // -------- COMPONENT RENDERING --------
  return (
    <div id="statsContainer">
      {/* Company 1 Results Table */}
      <table>
        <thead>
          <tr><th colSpan="3">{company1}</th></tr> {/* Company header */}
          <tr>
            <th>Price (x<sub>i</sub>)</th>        {/* Price column */}
            <th>(x<sub>i</sub> - x̄)</th>          {/* Deviation column */}
            <th>(x<sub>i</sub> - x̄)<sup>2</sup></th> {/* Squared deviation column */}
          </tr>
        </thead>
        <tbody>
          {generateCompanyRows(prices.c1Prices, stats1.mean)}  {/* Data rows */}
          <tr>
            <td><b>∑x<sub>i</sub></b> = {stats1.sum.toFixed(2)}</td> {/* Sum of prices */}
            <td></td> {/* Empty cell for spacing */}
            <td><b>∑(x<sub>i</sub> - x̄)<sup>2</sup></b> = {stats1.sumdev.toFixed(2)}</td> {/* Sum of squared deviations */}
          </tr>
        </tbody>
      </table>

      {/* Company 2 Results Table */}
      <table>
        <thead>
          <tr><th colSpan="3">{company2}</th></tr> {/* Company header */}
          <tr>
            <th>Price (x<sub>i</sub>)</th>        {/* Price column */}
            <th>(x<sub>i</sub> - x̄)</th>          {/* Deviation column */}
            <th>(x<sub>i</sub> - x̄)<sup>2</sup></th> {/* Squared deviation column */}
          </tr>
        </thead>
        <tbody>
          {generateCompanyRows(prices.c2Prices, stats2.mean)}  {/* Data rows */}
          <tr>
            <td><b>∑x<sub>i</sub></b> = {stats2.sum.toFixed(2)}</td> {/* Sum of prices */}
            <td></td> {/* Empty cell for spacing */}
            <td><b>∑(x<sub>i</sub> - x̄)<sup>2</sup></b> = {stats2.sumdev.toFixed(2)}</td> {/* Sum of squared deviations */}
          </tr>
        </tbody>
      </table>
    </div>
  );
}

export default ResultsDisplay;