/* ===================== COMPARATIVE ANALYSIS REPORT ===================== */
/* Generates risk/reward comparison for both companies */

import React from 'react';
import { calculateCompanyStats } from '../utils/calculations';

function AnalysisReport({ company1, company2, prices }) {
  // -------- STATISTICAL CALCULATIONS --------
  // Calculate metrics for both companies
  const stats1 = calculateCompanyStats(prices.c1Prices);
  const stats2 = calculateCompanyStats(prices.c2Prices);

  // -------- VOLATILITY ANALYSIS --------
  // Compare Standard Deviation (SD) and Coefficient of Variation (CV)
  const isSDEqual = stats1.sd === stats2.sd;  // Check if SDs are equal
  const useCV = isSDEqual;                    // Use CV only when SDs are equal

  // Determine which company is more volatile
  const company1MoreVolatile = useCV 
    ? stats1.cv > stats2.cv 
    : stats1.sd > stats2.sd;
  
  const company2MoreVolatile = useCV 
    ? stats2.cv > stats1.cv 
    : stats2.sd > stats1.sd;

  // -------- COMPONENT RENDERING --------
  return (
    <div id="analysisContainer">
      <div className="report-section">
        <center><h3 className="report-title">Report</h3></center> {/* Report header */}
        
        <div className="company-comparison">
          {/* Company 1 Analysis */}
          <div className="company-analysis">
            <h4>{company1}</h4> {/* Company name */}
            <ul className="analysis-list">
              {/* Core Metrics */}
              <li><strong>Mean (Average Price):</strong> ₹{stats1.mean.toFixed(2)}</li>
              <li><strong>Standard Deviation:</strong> ₹{stats1.sd.toFixed(2)}</li>
              <li><strong>Coeffiecient of Variation:</strong> {stats1.cv.toFixed(2)}%</li>
              
              {/* Volatility Analysis */}
              <li>
                <strong>Volatility:</strong> {isSDEqual 
                  ? `Equal SD but ${company1MoreVolatile ? 'higher' : 'lower'} CV means ${company1MoreVolatile ? 'more' : 'less'}` 
                  : `${company1MoreVolatile ? 'Higher' : 'Lower'} SD means ${company1MoreVolatile ? 'more' : 'less'}`} 
                price swings from average mean price.
              </li>
              
              {/* Risk Assessment */}
              <li>
                <strong>Risk:</strong> {company1MoreVolatile ? 'More' : 'Less'} price swings means 
                {company1MoreVolatile ? ' less' : ' more'} stability and {company1MoreVolatile ? 'higher' : 'lower'} risk.
              </li>
              
              {/* Return Potential */}
              <li>
                <strong>Returns:</strong> {company1MoreVolatile 
                  ? 'High volatility means higher returns with higher risk.' 
                  : 'Low volatility means stable returns with lower risk.'}
              </li>
              
              {/* Investment Conclusion */}
              <li className="conclusion-item">
                <strong>Conclusion:</strong> {company1MoreVolatile 
                  ? `If you are looking for higher potential returns and are willing to take on more risk on investment, then ${company1} is the better choice` 
                  : `If you are looking for stable returns with consistent growth and less risk on investment, then ${company1} is the better choice`}.
              </li>
            </ul>
          </div>

          {/* Company 2 Analysis */}
          <div className="company-analysis">
            <h4>{company2}</h4> {/* Company name */}
            <ul className="analysis-list">
              {/* Core Metrics */}
              <li><strong>Mean (Average Price):</strong> ₹{stats2.mean.toFixed(2)}</li>
              <li><strong>Standard Deviation:</strong> ₹{stats2.sd.toFixed(2)}</li>
              <li><strong>Coeffiecient of Variation:</strong> {stats2.cv.toFixed(2)}%</li>
              
              {/* Volatility Analysis */}
              <li>
                <strong>Volatility:</strong> {isSDEqual 
                  ? `Equal SD but ${company2MoreVolatile ? 'higher' : 'lower'} CV means ${company2MoreVolatile ? 'more' : 'less'}` 
                  : `${company2MoreVolatile ? 'Higher' : 'Lower'} SD means ${company2MoreVolatile ? 'more' : 'less'}`} 
                price swings from average mean price.
              </li>
              
              {/* Risk Assessment */}
              <li>
                <strong>Risk:</strong> {company2MoreVolatile ? 'More' : 'Less'} price swings means 
                {company2MoreVolatile ? ' less' : ' more'} stability and {company2MoreVolatile ? 'higher' : 'lower'} risk.
              </li>
              
              {/* Return Potential */}
              <li>
                <strong>Returns:</strong> {company2MoreVolatile 
                  ? 'High volatility means higher returns with higher risk.' 
                  : 'Low volatility means stable returns with lower risk.'}
              </li>
              
              {/* Investment Conclusion */}
              <li className="conclusion-item">
                <strong>Conclusion:</strong> {company2MoreVolatile 
                  ? `If you are looking for higher potential returns and are willing to take on more risk on investment, then ${company2} is the better choice` 
                  : `If you are looking for stable returns with consistent growth and less risk on investment, then ${company2} is the better choice`}.
              </li>
            </ul>
          </div>
        </div>
      </div>
    </div>
  );
}

export default AnalysisReport;