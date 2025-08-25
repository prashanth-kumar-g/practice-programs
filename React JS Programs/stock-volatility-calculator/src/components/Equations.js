/* ===================== MATHEMATICAL EQUATIONS DISPLAY ===================== */
/* Renders calculation formulas using MathJax */

import React, { useEffect } from 'react';
import { calculateCompanyStats } from '../utils/calculations';

function Equations({ company1, company2, prices }) {
  // -------- STATISTICAL CALCULATIONS --------
  // Calculate metrics for both companies
  const stats1 = calculateCompanyStats(prices.c1Prices);
  const stats2 = calculateCompanyStats(prices.c2Prices);

  // -------- EQUATION FORMATTING --------
  // Format equations in LaTeX for MathJax
  const company1Equation = `
    \\[\\therefore \\text{Mean } \\bar{x} = \\frac{\\sum x_i}{n} = \\frac{${stats1.sum.toFixed(2)}}{${prices.c1Prices.length}} = ${stats1.mean.toFixed(2)}\\]
    \\[\\therefore \\text{Standard Deviation (S.D)} = \\sqrt{\\frac{\\sum \\left(x_i - \\bar{x}\\right)^2}{n}} = \\sqrt{\\frac{${stats1.sumdev.toFixed(2)}}{${prices.c1Prices.length}}} = ${stats1.sd.toFixed(2)}\\]
    \\[\\therefore \\text{Coefficiet of Variation (C.V)} = \\frac{\\text{SD}}{\\bar{x}} = \\frac{${stats1.sd.toFixed(2)}}{${stats1.mean.toFixed(2)}} \\text{ * 100} = ${stats1.cv.toFixed(2)} \\text{ %}\\]
  `;

  const company2Equation = `
    \\[\\therefore \\text{Mean } \\bar{x} = \\frac{\\sum x_i}{n} = \\frac{${stats2.sum.toFixed(2)}}{${prices.c2Prices.length}} = ${stats2.mean.toFixed(2)}\\]
    \\[\\therefore \\text{Standard Deviation (S.D)} = \\sqrt{\\frac{\\sum \\left(x_i - \\bar{x}\\right)^2}{n}} = \\sqrt{\\frac{${stats2.sumdev.toFixed(2)}}{${prices.c2Prices.length}}} = ${stats2.sd.toFixed(2)}\\]
    \\[\\therefore \\text{Coefficiet of Variation (C.V)} = \\frac{\\text{SD}}{\\bar{x}} = \\frac{${stats2.sd.toFixed(2)}}{${stats2.mean.toFixed(2)}} \\text{ * 100} = ${stats2.cv.toFixed(2)} \\text{ %}\\]
  `;

  // -------- MATHJAX RENDERING --------
  // Re-render equations when prices change
  useEffect(() => {
    if (window.MathJax) {
      window.MathJax.Hub.Queue(["Typeset", window.MathJax.Hub]);
    }
  }, [prices]);

  // -------- COMPONENT RENDERING --------
  return (
    <div className="equationContainer visible">
      <div className="equation-wrapper">
        {/* Company 1 Equations */}
        <div id="company1Equation" dangerouslySetInnerHTML={{ __html: company1Equation }} />
      </div>
      <div className="equation-wrapper">
        {/* Company 2 Equations */}
        <div id="company2Equation" dangerouslySetInnerHTML={{ __html: company2Equation }} />
      </div>
    </div>
  );
}

export default Equations;