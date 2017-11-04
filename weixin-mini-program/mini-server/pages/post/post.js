Page({
  data: {
    arrayo: [],
    loadingHidden: false
  },
  onLoad: function (options) {
    var that = this
    wx.request({
      url: '......./post.php?id=' + options.id,
      data: {
      },
      header: {
        'content-type': 'application/json'
      },
      success: function (res) {
        that.setData({
          arrayo: res.data,
          loadingHidden: true
        })
        wx.setNavigationBarTitle({
          title: res.data.title,
        })
      }
    })
  }
})