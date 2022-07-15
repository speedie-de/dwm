/* This contains most dwm layouts */

void
grid(Monitor *m) {
	unsigned int i, n, cx, cy, cw, ch, aw, ah, cols, rows;
	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next))
		n++;

	/* grid dimensions */
	for(rows = 0; rows <= n/2; rows++)
		if(rows*rows >= n)
			break;
	cols = (rows && (rows - 1) * rows >= n) ? rows - 1 : rows;

	/* window geoms (cell height/width) */
	ch = m->wh / (rows ? rows : 1);
	cw = m->ww / (cols ? cols : 1);
	for(i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
		cx = m->wx + (i / rows) * cw;
		cy = m->wy + (i % rows) * ch;
		/* adjust height/width of last row/column's windows */
		ah = ((i + 1) % rows == 0) ? m->wh - ch * rows : 0;
		aw = (i >= rows * (cols - 1)) ? m->ww - cw * cols : 0;
		resize(c, cx, cy, cw - 2 * c->bw + aw, ch - 2 * c->bw + ah, False);
		i++;
	}
}
void
fibonacci(Monitor *mon, int s) {
	unsigned int i, n, nx, ny, nw, nh;
	Client *c;

	for(n = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next), n++);
	if(n == 0)
		return;
	
	nx = mon->wx;
	ny = 0;
	nw = mon->ww;
	nh = mon->wh;
	
	for(i = 0, c = nexttiled(mon->clients); c; c = nexttiled(c->next)) {
		if((i % 2 && nh / 2 > 2 * c->bw)
		   || (!(i % 2) && nw / 2 > 2 * c->bw)) {
			if(i < n - 1) {
				if(i % 2)
					nh /= 2;
				else
					nw /= 2;
				if((i % 4) == 2 && !s)
					nx += nw;
				else if((i % 4) == 3 && !s)
					ny += nh;
			}
			if((i % 4) == 0) {
				if(s)
					ny += nh;
				else
					ny -= nh;
			}
			else if((i % 4) == 1)
				nx += nw;
			else if((i % 4) == 2)
				ny += nh;
			else if((i % 4) == 3) {
				if(s)
					nx += nw;
				else
					nx -= nw;
			}
			if(i == 0)
			{
				if(n != 1)
					nw = mon->ww * mon->mfact;
				ny = mon->wy;
			}
			else if(i == 1)
				nw = mon->ww - nw;
			i++;
		}
		resize(c, nx, ny, nw - 2 * c->bw, nh - 2 * c->bw, False);
	}
}

void
dwindle(Monitor *mon) {
	fibonacci(mon, 1);
}

void
spiral(Monitor *mon) {
	fibonacci(mon, 0);
}
void
tcl(Monitor * m)
{
	int x, y, h, w, mw, sw, bdw;
	unsigned int i, n;
	Client * c;

	for (n = 0, c = nexttiled(m->clients); c;
	        c = nexttiled(c->next), n++);

	if (n == 0)
		return;

	c = nexttiled(m->clients);

	mw = m->mfact * m->ww;
	sw = (m->ww - mw) / 2;
	bdw = (2 * c->bw);
	resize(c,
	       n < 3 ? m->wx : m->wx + sw,
	       m->wy,
	       n == 1 ? m->ww - bdw : mw - bdw,
	       m->wh - bdw,
	       False);

	if (--n == 0)
		return;

	w = (m->ww - mw) / ((n > 1) + 1);
	c = nexttiled(c->next);

	if (n > 1)
	{
		x = m->wx + ((n > 1) ? mw + sw : mw);
		y = m->wy;
		h = m->wh / (n / 2);

		if (h < bh)
			h = m->wh;

		for (i = 0; c && i < n / 2; c = nexttiled(c->next), i++)
		{
			resize(c,
			       x,
			       y,
			       w - bdw,
			       (i + 1 == n / 2) ? m->wy + m->wh - y - bdw : h - bdw,
			       False);

			if (h != m->wh)
				y = c->y + HEIGHT(c);
		}
	}

	x = (n + 1 / 2) == 1 ? mw : m->wx;
	y = m->wy;
	h = m->wh / ((n + 1) / 2);

	if (h < bh)
		h = m->wh;

	for (i = 0; c; c = nexttiled(c->next), i++)
	{
		resize(c,
		       x,
		       y,
		       (i + 1 == (n + 1) / 2) ? w - bdw : w - bdw,
		       (i + 1 == (n + 1) / 2) ? m->wy + m->wh - y - bdw : h - bdw,
		       False);

		if (h != m->wh)
			y = c->y + HEIGHT(c);
	}
}

static void
bstack(Monitor *m) {
	int w, h, mh, mx, tx, ty, tw;
	unsigned int i, n;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;
	if (n > m->nmaster) {
		mh = m->nmaster ? m->mfact * m->wh : 0;
		tw = m->ww / (n - m->nmaster);
		ty = m->wy + mh;
	} else {
		mh = m->wh;
		tw = m->ww;
		ty = m->wy;
	}
	for (i = mx = 0, tx = m->wx, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
		if (i < m->nmaster) {
			w = (m->ww - mx) / (MIN(n, m->nmaster) - i);
			resize(c, m->wx + mx, m->wy, w - (2 * c->bw), mh - (2 * c->bw), 0);
			mx += WIDTH(c);
		} else {
			h = m->wh - mh;
			resize(c, tx, ty, tw - (2 * c->bw), h - (2 * c->bw), 0);
			if (tw != m->ww)
				tx += WIDTH(c);
		}
	}
}

static void
bstackhoriz(Monitor *m) {
	int w, mh, mx, tx, ty, th;
	unsigned int i, n;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;
	if (n > m->nmaster) {
		mh = m->nmaster ? m->mfact * m->wh : 0;
		th = (m->wh - mh) / (n - m->nmaster);
		ty = m->wy + mh;
	} else {
		th = mh = m->wh;
		ty = m->wy;
	}
	for (i = mx = 0, tx = m->wx, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
		if (i < m->nmaster) {
			w = (m->ww - mx) / (MIN(n, m->nmaster) - i);
			resize(c, m->wx + mx, m->wy, w - (2 * c->bw), mh - (2 * c->bw), 0);
			mx += WIDTH(c);
		} else {
			resize(c, tx, ty, m->ww - (2 * c->bw), th - (2 * c->bw), 0);
			if (th != m->wh)
				ty += HEIGHT(c);
		}
	}
}

void
horizgrid(Monitor *m) {
	Client *c;
	unsigned int n, i;
	int w = 0;
	int ntop, nbottom = 0;

	/* Count windows */
	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);

	if(n == 0)
		return;
	else if(n == 1) { /* Just fill the whole screen */
		c = nexttiled(m->clients);
		resize(c, m->wx, m->wy, m->ww - (2*c->bw), m->wh - (2*c->bw), False);
	} else if(n == 2) { /* Split vertically */
		w = m->ww / 2;
		c = nexttiled(m->clients);
		resize(c, m->wx, m->wy, w - (2*c->bw), m->wh - (2*c->bw), False);
		c = nexttiled(c->next);
		resize(c, m->wx + w, m->wy, w - (2*c->bw), m->wh - (2*c->bw), False);
	} else {
		ntop = n / 2;
		nbottom = n - ntop;
		for(i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
			if(i < ntop)
				resize(c, m->wx + i * m->ww / ntop, m->wy, m->ww / ntop - (2*c->bw), m->wh / 2 - (2*c->bw), False);
			else
				resize(c, m->wx + (i - ntop) * m->ww / nbottom, m->wy + m->wh / 2, m->ww / nbottom - (2*c->bw), m->wh / 2 - (2*c->bw), False);
		}
	}
}

void 
tatami(Monitor *m) {
	unsigned int i, n, nx, ny, nw, nh,
				 mats, tc,
				 tnx, tny, tnw, tnh;
	Client *c;

	for(n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), ++n);
	if(n == 0)
		return;
	
	nx = m->wx;
	ny = 0;
	nw = m->ww;
	nh = m->wh;
	
	c = nexttiled(m->clients);
	
	if(n != 1)  nw = m->ww * m->mfact;
				ny = m->wy;
				
	resize(c, nx, ny, nw - 2 * c->bw, nh - 2 * c->bw, False);
	
	c = nexttiled(c->next);
	
	nx += nw;
	nw = m->ww - nw;
	
	if(n>1)
	{
	
	tc = n-1;
	mats = tc/5;
	
	nh/=(mats + (tc % 5 > 0));
	
	for(i = 0; c && (i < (tc % 5)); c = nexttiled(c->next))
	{
		tnw=nw;
		tnx=nx;
		tnh=nh;
		tny=ny;
		switch(tc - (mats*5))
				{
					case 1://fill
						break;
					case 2://up and down
						if((i % 5) == 0) //up
						tnh/=2;
						else if((i % 5) == 1) //down
						{
							tnh/=2;
							tny += nh/2;
						}
						break;
					case 3://bottom, up-left and up-right
						if((i % 5) == 0) //up-left
						{
						tnw = nw/2;
						tnh = (2*nh)/3;
						}
						else if((i % 5) == 1)//up-right
						{
							tnx += nw/2;
							tnw = nw/2;
							tnh = (2*nh)/3;
						}
						else if((i % 5) == 2)//bottom
						{
							tnh = nh/3;
							tny += (2*nh)/3;	
						}
						break;
					case 4://bottom, left, right and top
						if((i % 5) == 0) //top
						{
							tnh = (nh)/4;
						}
						else if((i % 5) == 1)//left
						{
							tnw = nw/2;
							tny += nh/4;
							tnh = (nh)/2;
						}
						else if((i % 5) == 2)//right
						{
							tnx += nw/2;
							tnw = nw/2;
							tny += nh/4;
							tnh = (nh)/2;
						}
						else if((i % 5) == 3)//bottom
						{
							tny += (3*nh)/4;
							tnh = (nh)/4;
						}
						break;
				}
		++i;
		resize(c, tnx, tny, tnw - 2 * c->bw, tnh - 2 * c->bw, False);
	}
	
	++mats;
	
	for(i = 0; c && (mats>0); c = nexttiled(c->next)) {

			if((i%5)==0)
			{
			--mats;
			if(((tc % 5) > 0)||(i>=5))
			ny+=nh;
			}
			
			tnw=nw;
			tnx=nx;
			tnh=nh;
			tny=ny;
			

			switch(i % 5)
			{
				case 0: //top-left-vert
					tnw = (nw)/3;
					tnh = (nh*2)/3;
					break;
				case 1: //top-right-hor
					tnx += (nw)/3;
					tnw = (nw*2)/3;
					tnh = (nh)/3;
					break;
				case 2: //center
					tnx += (nw)/3;
					tnw = (nw)/3;
					tny += (nh)/3;
					tnh = (nh)/3;
					break;
				case 3: //bottom-right-vert
					tnx += (nw*2)/3;
					tnw = (nw)/3;
					tny += (nh)/3;
					tnh = (nh*2)/3;
					break;
				case 4: //(oldest) bottom-left-hor
					tnw = (2*nw)/3;
					tny += (2*nh)/3;
					tnh = (nh)/3;
					break;
				default:
					break;
			}
			
			++i;
			//i%=5;
		resize(c, tnx, tny, tnw - 2 * c->bw, tnh - 2 * c->bw, False);
		}
	}
}

void
tilewide(Monitor *m)
{
        unsigned int i, n, w, h, mw, mx, ty;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;
	if (n > m->nmaster)
		mw = m->nmaster ? m->ww * m->mfact : 0;
	else
		mw = m->ww;
	for (i = mx = ty = 0, c = nexttiled(m->clients); c;
	     c = nexttiled(c->next), i++)
		if (i < m->nmaster) {
		        w = (mw - mx) / (MIN(n, m->nmaster) - i);
		        resize(c, m->wx + mx, m->wy, w - (2*c->bw), (m->wh - ty) - (2*c->bw), 0);
		        if  (mx + WIDTH(c) < m->ww)
		                mx += WIDTH(c);
		} else {
			h = (m->wh - ty) / (n - i);
			resize(c, m->wx + mw, m->wy + ty, m->ww - mw - (2*c->bw), h - (2*c->bw), 0);
			if (ty + HEIGHT(c) < m->wh)
				ty += HEIGHT(c);
		}
}

void
stairs(Monitor *m)
{
	unsigned int i, n, h, mw, my;
	unsigned int ox, oy, ow, oh; /* stair offset values */
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	if (n > m->nmaster)
		mw = m->nmaster ? m->ww * m->mfact : 0;
	else
		mw = m->ww - m->gappx;

	for (i = 0, my = m->gappx, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++) {
		if (i < m->nmaster) {
			h = (m->wh - my) / (MIN(n, m->nmaster) - i) - m->gappx;
			resize(c, m->wx + m->gappx, m->wy + my, mw - (2 * c->bw) - m->gappx, h - (2 * c->bw), 0);
			if (my + HEIGHT(c) + m->gappx < m->wh)
				my += HEIGHT(c) + m->gappx;
		} else {
			oy = i - m->nmaster;
			ox = stairdirection ? n - i - 1 : (stairsamesize ? i - m->nmaster : 0);
			ow = stairsamesize ? n - m->nmaster - 1 : n - i - 1;
			oh = stairsamesize ? ow : i - m->nmaster;
			resize(c,
			       m->wx + mw + (ox * stairpx) + m->gappx,
			       m->wy + (oy * stairpx) + m->gappx,
			       m->ww - mw - (2 * c->bw) - (ow * stairpx) - (2 * m->gappx),
			       m->wh - (2 * c->bw) - (oh * stairpx) - (2 * m->gappx),
			       0);
		}
	}
}

