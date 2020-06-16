#include "x++/X.h"

static void _on_repaint(xwin_t* xw, graph_t* g) {
	if(xw == NULL || g == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doRepaint(g);
}

static void _on_min(xwin_t* xw) {
	if(xw == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doMin();
}

static void _on_resize(xwin_t* xw) {
	if(xw == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doResize();
}

static void _on_focus(xwin_t* xw) {
	if(xw == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doFocus();
}

static void _on_unfocus(xwin_t* xw) {
	if(xw == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doUnfocus();
}

static void _on_loop(xwin_t* xw) {
	if(xw == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doLoop();
}

static void _on_event(xwin_t* xw, xevent_t* ev) {
	if(xw == NULL)
		return;
	XWin* xwin = (XWin*)xw->data;
	if(xwin == NULL)
		return;
	xwin->__doEvent(ev);
}

bool XWin::open(int x, int y, uint32_t w, uint32_t h, const char* title, uint32_t style) {
	if(xwin != NULL)
		x_close(xwin);

	xwin = x_open(x, y, w, h, title, style);
	if(xwin == NULL)
		return false;
	xwin->data = this;
	xwin->on_repaint = _on_repaint;
	xwin->on_min = _on_min;
	xwin->on_resize = _on_resize;
	xwin->on_focus = _on_focus;
	xwin->on_unfocus = _on_unfocus;
	xwin->on_loop = _on_loop;
	xwin->on_event = _on_event;
	return true;
}

void XWin::close() {
	if(xwin != NULL) {
		xwin->terminated = true;
	}
}

bool XWin::setVisible(bool visible) {
	if(xwin == NULL)
		return false;
	x_set_visible(xwin, visible);
	return true;
}

void XWin::run() {
	if(xwin == NULL)
		return;
	
	x_run(xwin);

	x_close(xwin);
	xwin = NULL;
}

bool XWin::updateInfo(const xinfo_t& xinfo) {
	if(xwin == NULL)	
		return false;
	return (x_update_info(xwin, &xinfo) == 0);
}

bool XWin::getInfo(xinfo_t& xinfo) {
	if(xwin == NULL)	
		return false;
	return (x_get_info(xwin, &xinfo) == 0);
}

bool XWin::screenInfo(xscreen_t& scr) {
	return (x_screen_info(&scr) == 0);
}

bool XWin::isTop(void) {
	if(xwin == NULL)	
		return false;
	return (x_is_top(xwin) == 0);
}

void XWin::repaint() {
	if(xwin == NULL)	
		return;
	x_repaint(xwin);
}
