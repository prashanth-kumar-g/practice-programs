import express from 'express';

import {adminlogin,adminsignup} from './controller.js';

const router = express.Router();

router.get('/login',adminlogin);

router.get('/signup',adminsignup);

export default router;