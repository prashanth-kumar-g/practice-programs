import React, { Component } from "react"; 
import PropTypes from "prop-types"; 

class CourseCard extends Component { 
render() { 
return (  
<div className="course-card"> 
<h2>{this.props.title}</h2> 
<p><strong>Duration:</strong> {this.props.duration} weeks</p> 
<p><strong>Instructor:</strong> {this.props.instructor}</p> 
</div> 
);
}
}

CourseCard.propTypes = { 
title: PropTypes.string.isRequired, 
duration: PropTypes.number.isRequired, 
instructor: PropTypes.string.isRequired, 
}; 

export default CourseCard; 