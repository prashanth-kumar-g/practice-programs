/* ===================== INTERACTIVE CHART VISUALIZATION ===================== */
/* Creates price deviation charts using Plotly.js */

import React, { useEffect } from 'react';
import { createCharts } from '../utils/graphUtils';

function Charts({ company1, company2, prices, timeframe }) {
  // -------- CHART CREATION --------
  // Generate charts when component mounts or data changes
  useEffect(() => {
    // Calculate mean and SD for both companies
    const calculateStats = (prices) => {
      const mean = prices.reduce((sum, val) => sum + val, 0) / prices.length;
      const sd = Math.sqrt(
        prices.reduce((sum, val) => {
          const deviation = val - mean;
          return sum + deviation ** 2;
        }, 0) / prices.length
      );
      return { mean, sd };
    };

    // Prepare data for charts
    const company1Data = {
      name: company1,
      prices: prices.c1Prices,
      ...calculateStats(prices.c1Prices)
    };

    const company2Data = {
      name: company2,
      prices: prices.c2Prices,
      ...calculateStats(prices.c2Prices)
    };

    // Create charts
    createCharts(company1Data, company2Data, timeframe);
  }, [prices, company1, company2, timeframe]);

  // -------- COMPONENT RENDERING --------
  return (
    <div className="graphContainer active">
      <div className="graph-wrapper">
        {/* Company 1 Chart */}
        <div id="company1Chart" style={{ width: '660px', height: '550px' }}></div>
      </div>
      <div className="graph-wrapper">
        {/* Company 2 Chart */}
        <div id="company2Chart" style={{ width: '660px', height: '550px' }}></div>
      </div>
    </div>
  );
}

export default Charts;